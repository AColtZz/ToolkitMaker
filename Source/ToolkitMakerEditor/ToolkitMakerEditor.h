#pragma once

#include "UnrealEd.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Editor/LevelEditor/Public/LevelEditor.h"
#include "Editor/PropertyEditor/Public/PropertyEditing.h"
#include "IAssetTypeActions.h"
#include "IToolkitMakerModuleInterface.h"

class FToolkitMakerEditor : public IToolkitMakerModuleInterface
{
public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    virtual void AddModuleListeners() override;

    static inline FToolkitMakerEditor& Get()
    {
        return FModuleManager::LoadModuleChecked<FToolkitMakerEditor>("ToolkitMakerEditor");
    }

    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("ToolkitMakerEditor");
    }

public:
    void AddMenuExtension(const FMenuExtensionDelegate& extensionDelegate, FName extensionHook, const TSharedPtr<FUICommandList>& CommandList = NULL, EExtensionHook::Position position = EExtensionHook::Before);
    TSharedRef<FWorkspaceItem> GetMenuRoot() { return MenuRoot; };

protected:
    TSharedPtr<FExtensibilityManager> LevelEditorMenuExtensibilityManager;
    TSharedPtr<FExtender> MenuExtender;

    static TSharedRef<FWorkspaceItem> MenuRoot;

    void MakePulldownMenu(FMenuBarBuilder& menuBuilder);
    void FillPulldownMenu(FMenuBuilder& menuBuilder);

};