// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ToolkitMakerEditor : ModuleRules
{
    public ToolkitMakerEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
				// ... add public include paths required here ...
			}
            );


        PrivateIncludePaths.AddRange(
            new string[] {
				// ... add other private include paths required here ...
			}
            );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Projects",
                "Core",
                "Engine",
                "CoreUObject",
                "InputCore",
                "LevelEditor",
                "EditorFramework",
                "ToolMenus",
                "Slate",
                "SlateCore",
                "EditorStyle",
                "AssetTools",
                "EditorWidgets",
                "UnrealEd",
                "BlueprintGraph",
                "AnimGraph",
                "ComponentVisualizers",
                "ToolkitMaker",
            }
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "AppFramework",
                "EditorFramework",
                "Slate",
                "SlateCore",
                "AnimGraph",
                "UnrealEd",
                "KismetWidgets",
                "MainFrame",
                "PropertyEditor",
                "ComponentVisualizers",
                "ToolkitMaker"
            }
            );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
            );
    }
}
