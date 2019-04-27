#define _ARMA_

//ndefs=12
enum {
	destructengine = 2,
	destructdefault = 6,
	destructwreck = 7,
	destructtree = 3,
	destructtent = 4,
	stabilizedinaxisx = 1,
	stabilizedinaxisy = 2,
	destructno = 0,
	stabilizedinaxesboth = 3,
	stabilizedinaxesnone = 0,
	destructman = 5,
	destructbuilding = 1
};

class CfgPatches
{
	class TacticalApparel
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters"};
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class BattleBelt_ColorBase: Clothing
	{
		scope = 0;
		displayName = "Battle Belt";
		descriptionShort = "Can hold pistol magazines or small items. Has MOLLE for quick-attach pouches.";
		model = "\DZ\characters\belts\belt_leather_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		attachments[] = {"VestHolster", "VestBackpack", "Knife"};
		inventorySlot = "Hips";
		itemInfo[] = {"Clothing","Hips"};
		itemSize[] = {3,2};
		itemsCargoSize[] = {6,2};
		quickBarBonus = 2;
		weight = 40;
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLabels[] = {1.0,0.7,0.5,0.3,0.0};
					healthLevels[] = {{1.0,{"DZ\characters\belts\data\belt_leather_beige.rvmat"}},{0.5,{"DZ\characters\belts\data\belt_leather_beige_damage.rvmat"}},{0.0,{"DZ\characters\belts\data\belt_leather_beige_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\belts\belt_leather_m.p3d";
			female = "\DZ\characters\belts\belt_leather_f.p3d";
		};
	};
	class BattleBelt_Beige: BattleBelt_ColorBase
	{
		scope = 1;
		hiddenSelectionsTextures[] = {"\dz\characters\belts\data\belt_leather_co.paa","\dz\characters\belts\data\belt_leather_co.paa","\dz\characters\belts\data\belt_leather_co.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\belts\data\belt_leather_beige.rvmat","DZ\characters\belts\data\belt_leather_beige.rvmat","DZ\characters\belts\data\belt_leather_beige.rvmat"};
	};
	class ThreePointSling: Clothing
	{
		scope=2;
		displayName="Weapon Sling";
		descriptionShort="Three-point sling to have primary weapons close at hand.";
		model="\DZ\characters\vests\chest_holster_g.p3d";
		inventorySlot="Bow";
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Bow"
		};
		attachments[]=
		{
			"Shoulder"
		};
		quickBarBonus = 1;
		weight=30;
		itemSize[]={3,1};
		class ClothingTypes
		{
			male="\DZ\characters\vests\chest_holster_m.p3d";
			female="\DZ\characters\vests\chest_holster_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\vests\data\chest_holster.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\characters\vests\data\chest_holster.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\vests\data\chest_holster_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\characters\vests\data\chest_holster_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\characters\vests\data\chest_holster_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="SmershVest_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="SmershVest_drop_SoundSet";
					id=898;
				};
			};
		};
	};
};
