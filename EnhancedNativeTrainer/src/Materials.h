/*
	* Copyright (C) GTA:Multiplayer Team (https://wiki.gta-mp.net/index.php/Team)
	*
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are
	* met:
	*
	*     * Redistributions of source code must retain the above copyright
	*		notice, this list of conditions and the following disclaimer.
	*     * Redistributions in binary form must reproduce the above
	*		copyright notice, this list of conditions and the following disclaimer
	*		in the documentation and/or other materials provided with the
	*		distribution.
	*     * Neither the name of GTA-Network nor the names of its
	*		contributors may be used to endorse or promote products derived from
	*		this software without specific prior written permission.
	*
	* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	* A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
	* OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES INCLUDING, BUT NOT
	* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	* DATA, OR PROFITS; OR BUSINESS INTERRUPTION HOWEVER CAUSED AND ON ANY
	* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* INCLUDING NEGLIGENCE OR OTHERWISE ARISING IN ANY WAY OUT OF THE USE
	* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once

#include <cstdint>
#include <WinSock2.h>
#include <Windows.h>
#include <string>
#include <vector>
#include <cstdio>
#include <Psapi.h>

struct materialConfigData
{
public:
	float RAGE_FRICTION = 0.f;
	float RAGE_ELASTICITY = 0.f;
	float DENSITY = 0.f;
	float TYRE_GRIP = 0.f;
	float WET_GRIP = 0.f;
	float TYRE_DRAG = 0.f;
	float TOP_SPEED_MULT = 0.f;
	float SOFTNESS = 0.f;
	float NOISINES = 0.f;
	float PENETRATION_RESISTANCE = 0.f;

	materialConfigData() = default;
	materialConfigData(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10)
	{
		RAGE_FRICTION = a1;
		RAGE_ELASTICITY = a2;
		DENSITY = a3;
		TYRE_GRIP = a4;
		WET_GRIP = a5;
		TYRE_DRAG = a6;
		TOP_SPEED_MULT = a7;
		SOFTNESS = a8;
		NOISINES = a9;
		PENETRATION_RESISTANCE = a10;
	}
};

static materialConfigData originalMaterialData[] =
{

	/*	
		# MATERIAL
		RAGE_FRICTION
		RAGE_ELASTICITY
		DENSITY
		TYRE_GRIP
		WET_GRIP
		TYRE_DRAG
		TOP_SPEED_MULT
		SOFTNESS
		NOISINES
		PENETRATION / RESISTANCE																																																		
	*/
	materialConfigData{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }, // DEFAULT
	materialConfigData{ 1.0f, 0.3f, 7850.5f, 1.0f, -0.10f, 0.0f, 1.0f, 0.95f, 0.0f, 1.0f }, // CONCRETE
	materialConfigData{ 0.8f, 0.4f, 4900.0f, 0.90f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // CONCRETE_POTHOLE
	materialConfigData{ 0.6f, 0.3f, 7850.5f, 1.0f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // CONCRETE_DUSTY
	materialConfigData{ 1.0f, 0.4f, 6300.0f, 1.0f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // TARMAC
	materialConfigData{ 0.7f, 0.4f, 6300.0f, 0.90f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // TARMAC_PAINTED
	materialConfigData{ 0.7f, 0.4f, 4900.0f, 0.90f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // TARMAC_POTHOLE
	materialConfigData{ 1.0f, 0.3f, 6300.0f, 0.92f, -0.12f, 0.04f, 0.6f, 0.95f, 0.0f, 1.0f }, // RUMBLE_STRIP
	materialConfigData{ 1.0f, 0.3f, 7000.0f, 1.0f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // BREEZE_BLOCK
	materialConfigData{ 0.9f, 0.4f, 7000.0f, 1.0f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // ROCK
	materialConfigData{ 0.6f, 0.3f, 7000.0f, 0.80f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // ROCK_MOSSY
	materialConfigData{ 0.8f, 0.4f, 7000.0f, 1.0f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // STONE
	materialConfigData{ 0.8f, 0.4f, 7000.0f, 1.0f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // COBBLESTONE
	materialConfigData{ 0.8f, 0.4f, 7000.0f, 1.0f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // BRICK
	materialConfigData{ 0.7f, 0.5f, 8970.5f, 0.90f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // MARBLE
	materialConfigData{ 0.9f, 0.4f, 7000.0f, 1.0f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // PAVING_SLAB
	materialConfigData{ 1.0f, 0.4f, 8130.5f, 1.0f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // SANDSTONE_SOLID
	materialConfigData{ 1.0f, 0.2f, 5075.0f, 1.0f, -0.10f, 0.0f, 0.6f, 0.95f, 0.0f, 1.0f }, // SANDSTONE_BRITTLE
};

static materialConfigData moddedMaterialData[] =
{
	/*
	# MATERIAL
	RAGE_FRICTION
	RAGE_ELASTICITY
	DENSITY
	TYRE_GRIP
	WET_GRIP
	TYRE_DRAG
	TOP_SPEED_MULT
	SOFTNESS
	NOISINES
	PENETRATION / RESISTANCE
	*/
	materialConfigData{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }, // DEFAULT
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // CONCRETE
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // CONCRETE_POTHOLE
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // CONCRETE_DUSTY
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // TARMAC
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // TARMAC_PAINTED
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // TARMAC_POTHOLE
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // RUMBLE_STRIP
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // BREEZE_BLOCK
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // ROCK
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // ROCK_MOSSY
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // STONE
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // COBBLESTONE
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // BRICK
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // MARBLE
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // PAVING_SLAB
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // SANDSTONE_SOLID
	materialConfigData{ 0.7f, 0.2f, 6055.0f, 0.70f, -0.10f, 0.07f, 0.6f, 0.95f, 0.0f, 1.0f }, // SANDSTONE_BRITTLE
};

static std::string materialTypes[] =
{
	{ "DEFAULT" },
	{ "CONCRETE" },
	{ "CONCRETE_POTHOLE" },
	{ "CONCRETE_DUSTY" },
	{ "TARMAC" },
	{ "TARMAC_PAINTED" },
	{ "TARMAC_POTHOLE" },
	{ "RUMBLE_STRIP" },
	{ "BREEZE_BLOCK" },
	{ "ROCK" },
	{ "ROCK_MOSSY" },
	{ "STONE" },
	{ "COBBLESTONE" },
	{ "BRICK" },
	{ "MARBLE" },
	{ "PAVING_SLAB" },
	{ "SANDSTONE_SOLID" },
	{ "SANDSTONE_BRITTLE" },
	{ "SAND_LOOSE" },
	{ "SAND_COMPACT" },
	{ "SAND_WET" },
	{ "SAND_TRACK" },
	{ "SAND_UNDERWATER" },
	{ "SAND_DRY_DEEP" },
	{ "SAND_WET_DEEP " },
	{ "ICE" },
	{ "ICE_TARMAC" },
	{ "SNOW_LOOSE" },
	{ "SNOW_COMPACT" },
	{ "SNOW_DEEP" },
	{ "SNOW_TARMAC" },
	{ "GRAVEL_SMALL" },
	{ "GRAVEL_LARGE" },
	{ "GRAVEL_DEEP " },
	{ "GRAVEL_TRAIN_TRACK" },
	{ "DIRT_TRACK" },
	{ "MUD_HARD" },
	{ "MUD_POTHOLE" },
	{ "MUD_SOFT" },
	{ "MUD_UNDERWATER" },
	{ "MUD_DEEP " },
	{ "MARSH" },
	{ "MARSH_DEEP" },
	{ "SOIL" },
	{ "CLAY_HARD" },
	{ "CLAY_SOFT" },
	{ "GRASS_LONG" },
	{ "GRASS" },
	{ "GRASS_SHORT" },
	{ "HAY" },
	{ "BUSHES" },
	{ "TWIGS" },
	{ "LEAVES" },
	{ "WOODCHIPS" },
	{ "TREE_BARK" },
	{ "METAL_SOLID_SMALL" },
	{ "METAL_SOLID_MEDIUM" },
	{ "METAL_SOLID_LARGE" },
	{ "METAL_HOLLOW_SMALL" },
	{ "METAL_HOLLOW_MEDIUM" },
	{ "METAL_HOLLOW_LARGE" },
	{ "METAL_CHAINLINK_SMALL" },
	{ "METAL_CHAINLINK_LARGE" },
	{ "METAL_CORRUGATED_IRON" },
	{ "METAL_GRILLE" },
	{ "METAL_RAILING" },
	{ "METAL_DUCT" },
	{ "METAL_GARAGE_DOOR" },
	{ "METAL_MANHOLE" },
	{ "WOOD_SOLID_SMALL" },
	{ "WOOD_SOLID_MEDIUM" },
	{ "WOOD_SOLID_LARGE" },
	{ "WOOD_SOLID_POLISHED" },
	{ "WOOD_FLOOR_DUSTY" },
	{ "WOOD_HOLLOW_SMALL" },
	{ "WOOD_HOLLOW_MEDIUM" },
	{ "WOOD_HOLLOW_LARGE" },
	{ "WOOD_CHIPBOARD" },
	{ "WOOD_OLD_CREAKY" },
	{ "WOOD_HIGH_DENSITY" },
	{ "WOOD_LATTICE" },
	{ "CERAMIC" },
	{ "ROOF_TILE" },
	{ "ROOF_FELT" },
	{ "FIBREGLASS " },
	{ "TARPAULIN" },
	{ "PLASTIC" },
	{ "PLASTIC_HOLLOW" },
	{ "PLASTIC_HIGH_DENSITY" },
	{ "PLASTIC_CLEAR" },
	{ "PLASTIC_HOLLOW_CLEAR" },
	{ "PLASTIC_HIGH_DENSITY_CLEAR" },
	{ "FIBREGLASS_HOLLOW" },
	{ "RUBBER" },
	{ "RUBBER_HOLLOW" },
	{ "LINOLEUM " },
	{ "LAMINATE " },
	{ "CARPET_SOLID" },
	{ "CARPET_SOLID_DUSTY" },
	{ "CARPET_FLOORBOARD" },
	{ "CLOTH " },
	{ "PLASTER_SOLID" },
	{ "PLASTER_BRITTLE" },
	{ "CARDBOARD_SHEET" },
	{ "CARDBOARD_BOX" },
	{ "PAPER " },
	{ "FOAM" },
	{ "FEATHER_PILLOW" },
	{ "POLYSTYRENE" },
	{ "LEATHER" },
	{ "TVSCREEN" },
	{ "SLATTED_BLINDS" },
	{ "GLASS_SHOOT_THROUGH" },
	{ "GLASS_BULLETPROOF" },
	{ "GLASS_OPAQUE" },
	{ "PERSPEX" },
	{ "CAR_METAL" },
	{ "CAR_PLASTIC" },
	{ "CAR_SOFTTOP" },
	{ "CAR_SOFTTOP_CLEAR" },
	{ "CAR_GLASS_WEAK" },
	{ "CAR_GLASS_MEDIUM" },
	{ "CAR_GLASS_STRONG" },
	{ "CAR_GLASS_BULLETPROOF" },
	{ "CAR_GLASS_OPAQUE" },
	{ "WATER" },
	{ "BLOOD" },
	{ "OIL" },
	{ "PETROL" },
	{ "FRESH_MEAT" },
	{ "DRIED_MEAT" },
	{ "EMISSIVE_GLASS" },
	{ "EMISSIVE_PLASTIC" },
	{ "VFX_METAL_ELECTRIFIED" },
	{ "VFX_METAL_WATER_TOWER" },
	{ "VFX_METAL_STEAM" },
	{ "VFX_METAL_FLAME" },
	{ "PHYS_NO_FRICTION" },
	{ "PHYS_GOLF_BALL" },
	{ "PHYS_TENNIS_BALL" },
	{ "PHYS_CASTER" },
	{ "PHYS_CASTER_RUSTY" },
	{ "PHYS_CAR_VOID" },
	{ "PHYS_PED_CAPSULE" },
	{ "PHYS_ELECTRIC_FENCE" },
	{ "PHYS_ELECTRIC_METAL" },
	{ "PHYS_BARBED_WIRE" },
	{ "PHYS_POOLTABLE_SURFACE" },
	{ "PHYS_POOLTABLE_CUSHION" },
	{ "PHYS_POOLTABLE_BALL" },
	{ "BUTTOCKS" },
	{ "THIGH_LEFT" },
	{ "SHIN_LEFT" },
	{ "FOOT_LEFT" },
	{ "THIGH_RIGHT" },
	{ "SHIN_RIGHT" },
	{ "FOOT_RIGHT" },
	{ "SPINE0" },
	{ "SPINE1" },
	{ "SPINE2" },
	{ "SPINE3" },
	{ "CLAVICLE_LEFT" },
	{ "UPPER_ARM_LEFT" },
	{ "LOWER_ARM_LEFT" },
	{ "HAND_LEFT" },
	{ "CLAVICLE_RIGHT" },
	{ "UPPER_ARM_RIGHT" },
	{ "LOWER_ARM_RIGHT" },
	{ "HAND_RIGHT" },
	{ "NECK" },
	{ "HEAD" },
	{ "ANIMAL_DEFAULT" },
	{ "CAR_ENGINE" },
	{ "PUDDLE" },
	{ "CONCRETE_PAVEMENT" },
	{ "BRICK_PAVEMENT" },
	{ "PHYS_DYNAMIC_COVER_BOUND" },
	{ "VFX_WOOD_BEER_BARREL" },
	{ "WOOD_HIGH_FRICTION" },
	{ "ROCK_NOINST" },
	{ "BUSHES_NOINST" },
	{ "METAL_SOLID_ROAD_SURFACE" },
	{ "TEMP_01" },
	{ "TEMP_02" },
	{ "TEMP_03" },
	{ "TEMP_04" },
	{ "TEMP_05" },
	{ "TEMP_06" },
	{ "TEMP_07" },
	{ "TEMP_08" },
	{ "TEMP_09" },
	{ "TEMP_10" },
	{ "TEMP_11" },
	{ "TEMP_12" },
	{ "TEMP_13" },
	{ "TEMP_14" },
	{ "TEMP_15" },
	{ "TEMP_16" },
	{ "TEMP_17" },
	{ "TEMP_18" },
	{ "TEMP_19" },
	{ "TEMP_20" },
	{ "TEMP_21" },
	{ "TEMP_22" },
	{ "TEMP_23" },
	{ "TEMP_24" },
	{ "TEMP_25" },
	{ "TEMP_26" },
	{ "TEMP_27" },
	{ "TEMP_28" },
	{ "TEMP_29" },
	{ "TEMP_30" }
};

static std::string materialTypeCategories[] =
{
	{ "VOID" }, // RAGE internal placeholder
	{ "GENERIC" },
	{ "CONCRETE_DUSTY" },
	{ "TARMAC_BRITTLE" },
	{ "SANDSTONE_BRITTLE" },
	{ "SAND_LOOSE" },
	{ "SAND_COMPACT" },
	{ "SAND_WET" },
	{ "SAND_UNDERWATER" },
	{ "SAND_DEEP" },
	{ "SAND_WET_DEEP" },
	{ "SNOW_LOOSE" },
	{ "SNOW_COMPACT" },
	{ "GRAVEL_DEEP" },
	{ "DIRT_DRY" },
	{ "MUD_SOFT" },
	{ "MUD_DEEP" },
	{ "MUD_UNDERWATER" },
	{ "GRASS" },
	{ "GRASS_SHORT" },
	{ "TREE_BARK" },
	{ "WOOD_DUSTY" },
	{ "WOOD_SPLINTER" },
	{ "CARPET_FABRIC" },
	{ "CARPET_FABRIC_DUSTY" },
	{ "PLASTIC_HOLLOW" },
	{ "PLASTER_BRITTLE" },
	{ "TVSCREEN" },
	{ "GLASS_BULLETPROOF" },
	{ "CAR_METAL" },
	{ "CAR_PLASTIC" },
	{ "CAR_GLASS" },
	{ "LIQUID_WATER" },
	{ "LIQUID_BLOOD" },
	{ "LIQUID_OIL" },
	{ "LIQUID_PETROL" },
	{ "LIQUID_MUD" },
	{ "FRESH_MEAT" },
	{ "DRIED_MEAT" },
	{ "PED_HEAD" },
	{ "PED_TORSO" },
	{ "PED_LIMB" },
	{ "PED_FOOT" },
	{ "PED_CAPSULE" }
};

struct MaterialAsset
{
	std::string _name;
	std::string _content;
	int8_t _type = 0;
	float _fl;
};

namespace rage
{
	class phMaterialGta
	{
	public:
		virtual ~phMaterialGta() = default; //
		/*virtual void Function1() = 0; //
		virtual void Function2() = 0; //
		virtual void Function3() = 0; //
		virtual void Function4() = 0; //
		virtual void Function5() = 0; //
		virtual void Function6() = 0; //
		virtual void Function7() = 0; //
		virtual void Function8() = 0; //
		virtual void Function9() = 0; //*/

		unsigned char N00000002; //0x0008 
		char pad_0x0009[0x7]; //0x0009
		__int64 N00000003; //0x0010 
		float RAGE_FRICTION; //0x0018 
		float RAGE_ELASTICITY; //0x001C 
		char pad_0x0020[0x10]; //0x0020
		DWORD materialIndexID; //0x0030 
		char pad_0x0034[0x8]; //0x0034
		__int32 N00000026; //0x003C 
		float DENSITY; //0x0040 
		float TYRE_GRIP; //0x0044 
		float WET_GRIP; //0x0048 
		float TYRE_DRAG; //0x004C 
		float TOP_SPEED_MULT; //0x0050 
		float unk; //0x0054 
		float SOFTNESS; //0x0058 
		float NOISINES; //0x005C 
		float PENETRATION_RESISTANCE; //0x0060 
		unsigned char N00000033; //0x0064 
		unsigned char N00000052; //0x0065 
		unsigned char N00000055; //0x0066 
		unsigned char N00000053; //0x0067 
		unsigned char flags; //0x0068 
		unsigned char N0000004B; //0x0069 
		unsigned char N00000059; //0x006A 
		unsigned char N0000004C; //0x006B 
		DWORD N0000003B; //0x006C 

	};//Size=0x0070
}