#include "ToolkitMakerEditor.h"
#include "IToolkitMakerModuleInterface.h"

// Modules
#include "MenuTool/MenuTool.h"
#include "TabTool/TabTool.h"

IMPLEMENT_GAME_MODULE(FToolkitMakerEditor, ToolkitMakerEditor)

void FToolkitMakerEditor::AddModuleListeners()
{
    // add tools later
    ModuleListeners.Add(MakeShareable(new MenuTool));
    ModuleListeners.Add(MakeShareable(new TabTool));
}

void FToolkitMakerEditor::StartupModule()
{
    if (!IsRunningCommandlet())
    {
        FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
        LevelEditorMenuExtensibilityManager = LevelEditorModule.GetMenuExtensibilityManager();
        MenuExtender = MakeShareable(new FExtender);
        MenuExtender->AddMenuBarExtension("Window", EExtensionHook::After, NULL, FMenuBarExtensionDelegate::CreateRaw(this, &FToolkitMakerEditor::MakePulldownMenu));
        LevelEditorMenuExtensibilityManager->AddExtender(MenuExtender);
    }

    IToolkitMakerModuleInterface::StartupModule();
}

void FToolkitMakerEditor::ShutdownModule()
{
    IToolkitMakerModuleInterface::ShutdownModule();
}

TSharedRef<FWorkspaceItem> FToolkitMakerEditor::MenuRoot = FWorkspaceItem::NewGroup(FText::FromString("Menu Root"));

void FToolkitMakerEditor::AddMenuExtension(const FMenuExtensionDelegate& extensionDelegate, FName extensionHook, const TSharedPtr<FUICommandList>& CommandList, EExtensionHook::Position position)
{
    MenuExtender->AddMenuExtension(extensionHook, position, CommandList, extensionDelegate);
}

void FToolkitMakerEditor::MakePulldownMenu(FMenuBarBuilder& menuBuilder)
{
    menuBuilder.AddPullDownMenu(
        FText::FromString("ToolkitMaker"),
        FText::FromString("Open the ToolkitMaker menu"),
        FNewMenuDelegate::CreateRaw(this, &FToolkitMakerEditor::FillPulldownMenu),
        "ToolkitMaker",
        FName(TEXT("ToolkitMakerMenu"))
    );
}

void FToolkitMakerEditor::FillPulldownMenu(FMenuBuilder& menuBuilder)
{
    // just a frame for tools to fill in
    menuBuilder.BeginSection("ExampleSection", FText::FromString("Section 1"));
    menuBuilder.AddMenuSeparator(FName("Section_1"));
    menuBuilder.EndSection();

    menuBuilder.BeginSection("ExampleSection", FText::FromString("Section 2"));
    menuBuilder.AddMenuSeparator(FName("Section_2"));
    menuBuilder.EndSection();
}