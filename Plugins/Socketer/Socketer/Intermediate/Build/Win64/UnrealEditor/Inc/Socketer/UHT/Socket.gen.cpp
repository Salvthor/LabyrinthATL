// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Socketer/Public/Socket.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSocket() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	SOCKETER_API UClass* Z_Construct_UClass_USocketerSocket();
	SOCKETER_API UClass* Z_Construct_UClass_USocketerSocket_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Socketer();
// End Cross Module References
	void USocketerSocket::StaticRegisterNativesUSocketerSocket()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USocketerSocket);
	UClass* Z_Construct_UClass_USocketerSocket_NoRegister()
	{
		return USocketerSocket::StaticClass();
	}
	struct Z_Construct_UClass_USocketerSocket_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USocketerSocket_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Socketer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USocketerSocket_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketerSocket_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Socket.h" },
		{ "ModuleRelativePath", "Public/Socket.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USocketerSocket_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USocketerSocket>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USocketerSocket_Statics::ClassParams = {
		&USocketerSocket::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USocketerSocket_Statics::Class_MetaDataParams), Z_Construct_UClass_USocketerSocket_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_USocketerSocket()
	{
		if (!Z_Registration_Info_UClass_USocketerSocket.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USocketerSocket.OuterSingleton, Z_Construct_UClass_USocketerSocket_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USocketerSocket.OuterSingleton;
	}
	template<> SOCKETER_API UClass* StaticClass<USocketerSocket>()
	{
		return USocketerSocket::StaticClass();
	}
	USocketerSocket::USocketerSocket(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USocketerSocket);
	USocketerSocket::~USocketerSocket() {}
	struct Z_CompiledInDeferFile_FID_Progetti_Progetti_Unreal_LabyrinthATL_Plugins_Socketer_Socketer_Source_Socketer_Public_Socket_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Progetti_Progetti_Unreal_LabyrinthATL_Plugins_Socketer_Socketer_Source_Socketer_Public_Socket_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USocketerSocket, USocketerSocket::StaticClass, TEXT("USocketerSocket"), &Z_Registration_Info_UClass_USocketerSocket, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USocketerSocket), 388773365U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Progetti_Progetti_Unreal_LabyrinthATL_Plugins_Socketer_Socketer_Source_Socketer_Public_Socket_h_2424084672(TEXT("/Script/Socketer"),
		Z_CompiledInDeferFile_FID_Progetti_Progetti_Unreal_LabyrinthATL_Plugins_Socketer_Socketer_Source_Socketer_Public_Socket_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Progetti_Progetti_Unreal_LabyrinthATL_Plugins_Socketer_Socketer_Source_Socketer_Public_Socket_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
