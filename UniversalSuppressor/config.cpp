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

//Class E:\SteamLibrary\steamapps\common\DayZ\Addons\UniversalSuppressor\config.bin{
class CfgPatches
{
	class UniversalSuppressor
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgRecipes{};
class cfgVehicles
{
	class Inventory_Base;
	class ItemBarrel: Inventory_Base{};
	class ItemSuppressor: Inventory_Base
	{
		scope = 0;
		inventorySlot = "weaponMuzzle";
		simulation = "ItemSuppressor";
		itemSize[] = {1,1};
		selectionFireAnim = "zasleh";
		soundIndex = 1;
		muzzlePos = "usti hlavne";
		barrelArmor = 60000;
		recoilModifier[] = {1,1,1};
		isMeleeWeapon = 1;
	};
	class TrekSuppressor: ItemSuppressor
	{
		scope = 2;
		displayName = "Gemtech Rifle Suppressor";
		descriptionShort = "$STR_cfgVehicles_PistolSuppressor1";
		model = "\dz\weapons\attachments\muzzle\suppressor_45acp.p3d";
		rotationFlags = 17;
		reversed = 0;
		weight = 100;
		itemSize[] = {3,1};
		lootCategory = "Attachments";
		lootTag[] = {"Military_east","Military_west","Police","Civilian"};
		inventorySlot = "suppressorImpro";
		simulation = "ItemSuppressor";
		noiseShootModifier = -0.8;
		barrelArmor = 60000;
		recoilModifier[] = {1,1,1};
		selectionFireAnim = "zasleh";
		soundIndex = 1;
		muzzlePos = "usti hlavne";
		class Particles
		{
			class OnFire
			{
				class MuzzleFlash
				{
					overrideParticle = "weapon_shot_akm_02";
				};
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\weapons\attachments\data\gemtech.rvmat","DZ\weapons\attachments\data\gemtech_damage.rvmat","DZ\weapons\attachments\data\gemtech_destruct.rvmat"};
		};
	};
};
//};