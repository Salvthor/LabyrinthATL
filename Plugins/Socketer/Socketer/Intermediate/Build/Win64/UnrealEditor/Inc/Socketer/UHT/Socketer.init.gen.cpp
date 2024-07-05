// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSocketer_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Socketer;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Socketer()
	{
		if (!Z_Registration_Info_UPackage__Script_Socketer.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Socketer",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x776174A7,
				0x522B2A93,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Socketer.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Socketer.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Socketer(Z_Construct_UPackage__Script_Socketer, TEXT("/Script/Socketer"), Z_Registration_Info_UPackage__Script_Socketer, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x776174A7, 0x522B2A93));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
