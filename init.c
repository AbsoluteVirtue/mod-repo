
void main()
{
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	weather.GetRain().Set( 0, 0, 1);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

    if ((month == reset_month) && (day < reset_day))
    {
        GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
    }
    else
    {
        if ((month == reset_month + 1) && (day > reset_day))
        {
            GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
        }
        else
        {
            if ((month < reset_month) || (month > reset_month + 1))
            {
                GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
            }
        }
    }
}

class CustomMission: MissionServer
{	
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			int rndHlt = Math.RandomInt(55,100);
			itemEnt.SetHealth("","",rndHlt);
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		
		return m_player;
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemEnt;
		ItemBase itemBs;

		player.GetStatWater().Set(1000);
		player.GetStatEnergy().Set(1000);
		player.GetStatStamina().Set(100);

		player.RemoveAllItems();

		EntityAI itemWeapon;
		itemWeapon = player.GetHumanInventory().CreateInHands( "M4A1_Green" );
		itemWeapon.GetInventory().CreateAttachment( "M4_RISHndgrd_Green" );
		itemWeapon.GetInventory().CreateAttachment( "M4_MPBttstck" );
		itemWeapon.GetInventory().CreateAttachment( "ACOGOptic" );
		itemWeapon.GetInventory().CreateAttachment( "UniversalLight" );

		player.GetInventory().CreateAttachment("HikingJacket_Red");
		player.GetInventory().CreateAttachment("CargoPants_Black");
		player.GetInventory().CreateAttachment("HikingBootsLow_Blue");

		EntityAI itemVest;
		itemVest = player.GetInventory().CreateAttachment("SmershVest");
		if ( itemVest ) {
			itemVest.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			itemVest.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			itemVest.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			itemVest.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			itemVest.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			itemVest.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
		}

		EntityAI itemTop;
		itemTop = player.FindAttachmentBySlotName("Body");
		if ( itemTop ) {		
			itemEnt = itemTop.GetInventory().CreateInInventory("M4_Suppressor");
			itemEnt.SetAllowDamage(false);
		}

		EntityAI itemBottom;
		itemBottom = player.FindAttachmentBySlotName("Legs");
		if ( itemBottom ) {
			itemEnt = itemBottom.GetInventory().CreateInInventory("Rag");
			if ( Class.CastTo(itemBs, itemEnt ) )
				itemBs.SetQuantity(6);
		}

		EntityAI itemBack;
		itemBack = player.GetInventory().CreateAttachment("HuntingBag");
		if ( itemBack ) {
			itemBack.GetInventory().CreateInInventory("Matchbox");
			itemBack.GetInventory().CreateInInventory("TunaCan");
			itemBack.GetInventory().CreateInInventory("SteakKnife");
			itemBack.GetInventory().CreateInInventory("Canteen");
			itemBack.GetInventory().CreateInInventory("Battery9V");
		}
	}
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}