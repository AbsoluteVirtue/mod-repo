class DefaultPlayerSetup
{
    private PlayerBase player;
    private ref TStringArray clothesComponents;
	private ref TStringArray itemsComponents;
    private EntityAI weapon;
	private string sWeapon = "Machete";
	private string sCharacter;
   
    void DefaultPlayerSetup(PlayerBase pIn)
    {		
        player = pIn;
		
		player.GetStatWater().Set(1000);
		player.GetStatEnergy().Set(1000);
		player.GetStatStamina().Set(100);

		player.RemoveAllItems();
			
		setPlayerCharacter();
		setPlayerEquipment();
    }
	
	private void setPlayerCharacter() {
		//Math.RandomInt(0, 3)
		switch(5) {
			case 0:
				sCharacter = "soldier";
				sWeapon = "AKM";
				break;
			case 1:
				sCharacter = "policeman";
				sWeapon = "MakarovIJ70";
				break;
			case 2:
				sCharacter = "medic";
				sWeapon = "BrassKnuckles_Dull";
				break;
			default:
				break;
		}
	}
	
	private void setPlayerEquipment()
	{
		switch(sCharacter) {
			case "soldier":
				clothesComponents = {"GorkaEJacket_Flat", "GorkaPants_Flat", "JungleBoots_Black", "BeanieHat_Black", "OMNOGloves_Brown", "SmershBag"};
				itemsComponents = {"TunaCan", "Canteen", "CombatKnife"};
				break;
			case "policeman":
				clothesComponents = {"PolicePants", "PoliceJacket", "PoliceVest", "PoliceCap"};
				itemsComponents = {"Handcuffs", "HandcuffKeys", "TunaCan", "WaterBottle", "CanOpener"};
				break;
			case "medic":
				clothesComponents = {"ParamedicJacket_Crimson", "ParamedicPants_Crimson", "AthleticShoes_Blue", "Ushanka_Black", "DryBag_Red"};
				itemsComponents = {"WaterBottle", "TunaCan", "KitchenKnife", "FirstAidKit", "Morphine", "Epinephrine", "BandageDressing", "BandageDressing", "BandageDressing"};
				break;
			default:
				clothesComponents = {};
				itemsComponents = {"WaterBottle", "Rag", "TunaCan", "SteakKnife"};
				break;
		}
		setPlayerClothes();
		setPlayerItems();
		setPlayerWeapon();
	}
	
	private void setPlayerWeapon() {
		weapon = player.GetHumanInventory().CreateInHands(sWeapon);
		addAttachmentsWeapon();
	}
	
	private void addAttachmentsWeapon() 
	{
		switch(sWeapon) {
			case "AKM":
				weapon.GetInventory().CreateAttachment("AK_WoodBttstck");
				weapon.GetInventory().CreateAttachment("AK_WoodHndgrd");
				addMagazinesPlayer("Mag_AKM_30Rnd");
				break;
			case "M4A1":
				weapon.GetInventory().CreateAttachment("M4_CarryHandleOptic");
				weapon.GetInventory().CreateAttachment("M4_OEBttstck");
				weapon.GetInventory().CreateAttachment("M4_PlasticHndgrd");
				addMagazinesPlayer("Mag_STANAG_30Rnd");
				break;
			case "MakarovIJ70":
				addMagazinesPlayer("Mag_IJ70_8Rnd");
			default:
				break;
		}
	}
   
    private void setPlayerClothesDefault()
    {		
		TStringArray tops = {"Hoodie_Blue","Hoodie_Black","Hoodie_Brown","Hoodie_Green","Hoodie_Grey","Hoodie_Red"};
		TStringArray pants = {"Jeans_Black","Jeans_BlueDark","Jeans_Blue","Jeans_Brown","Jeans_Green","Jeans_Grey"};
		TStringArray shoes = {"AthleticShoes_Black","AthleticShoes_Blue","AthleticShoes_Brown","AthleticShoes_Green","AthleticShoes_Grey"};
		
        player.GetInventory().CreateAttachment(tops.GetRandomElement());
        player.GetInventory().CreateAttachment(pants.GetRandomElement());
        player.GetInventory().CreateAttachment(shoes.GetRandomElement());
		
		player.GetInventory().CreateAttachment("CourierBag");
    }
   
    private void setPlayerClothes()
    {		
        if (clothesComponents.Count() > 0)
        {
            for (int i = 0; i < clothesComponents.Count(); i++)
	        {
	            player.GetInventory().CreateInInventory(clothesComponents[i]);
	        }
        }
        else
        {
            setPlayerClothesDefault();
        }
    }
	
	private void setPlayerItems()
	{		
		if (itemsComponents.Count() > 0)
        {
            for (int i = 0; i < itemsComponents.Count(); i++)
	        {
	            player.GetInventory().CreateInInventory(itemsComponents[i]);
	        }
        }
	}
   
    private void addMagazinesPlayer(string sMagazine, int magCount=1)
    {
		for (int i = 0; i < magCount; i++)
        {
			player.GetInventory().CreateInInventory(sMagazine);
		}
    }
};