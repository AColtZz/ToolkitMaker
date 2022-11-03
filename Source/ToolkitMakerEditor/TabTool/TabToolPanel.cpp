#include "TabToolPanel.h"

#include "../ToolkitMakerEditor.h"
#include "../Widgets/SToolkitMakerDemo.h"

#define LOCTEXT_NAMESPACE "TabToolPanel"

class TabToolCommands : public TCommands<TabToolCommands>
{
public:
    TabToolCommands()
        : TCommands<TabToolCommands>(
            TEXT("TabTool"), // Context name for fast lookup
            FText::FromString("Example Tab tool"), // Context name for displaying
            NAME_None, // No parent context
            FEditorStyle::GetStyleSetName() // Icon Style Set
          ) { }

    virtual void RegisterCommands() override
    {
        UI_COMMAND(NewCommand, "New", "New File Command.", EUserInterfaceActionType::Button, FInputGesture());
        UI_COMMAND(OpenCommand, "Open", "Open File Command.", EUserInterfaceActionType::Button, FInputGesture());
        UI_COMMAND(OpenRecentCommand, "Open Recent", "Open Recent File Command.", EUserInterfaceActionType::Button, FInputGesture());
        UI_COMMAND(SaveCommand, "Save", "Save File Command.", EUserInterfaceActionType::Button, FInputGesture());
        UI_COMMAND(SaveAsCommand, "Save As", "Save File As Command.", EUserInterfaceActionType::Button, FInputGesture());
        UI_COMMAND(QuitCommand, "Quit", "Quit Command.", EUserInterfaceActionType::Button, FInputGesture());
    }

public:
    TSharedPtr<FUICommandInfo> NewCommand;
    TSharedPtr<FUICommandInfo> OpenCommand;
    TSharedPtr<FUICommandInfo> OpenRecentCommand;
    TSharedPtr<FUICommandInfo> SaveCommand;
    TSharedPtr<FUICommandInfo> SaveAsCommand;
    TSharedPtr<FUICommandInfo> QuitCommand;

};

void TabToolPanel::Construct(const FArguments& InArgs)
{
    tool = InArgs._Tool;
    if (tool.IsValid())
    {
        // do anything you need from tool object
        CommandList = MakeShareable(new FUICommandList);
        TabToolCommands::Register();
        MapCommands();
    }

    FMenuBarBuilder MenuBarBuilder = FMenuBarBuilder(TSharedPtr<FUICommandList>());

    MenuBarBuilder.AddPullDownMenu(
        LOCTEXT("FileLabel", "File"),
        FText::FromString("Demo Window"),
        FNewMenuDelegate::CreateSP(this, &TabToolPanel::FillMenuPulldownMenu),
        "File"
    );

    MenuBarBuilder.AddPullDownMenu(
        LOCTEXT("ExamplesLabel", "Examples"),
        FText::FromString("Examples Window"),
        FNewMenuDelegate::CreateSP(this, &TabToolPanel::FillExamplesPulldownMenu),
        "Examples"
    );

    MenuBarBuilder.AddPullDownMenu(
        LOCTEXT("ToolsLabel", "Tools"),
        FText::FromString("Tools Window"),
        FNewMenuDelegate::CreateSP(this, &TabToolPanel::FillToolsPulldownMenu),
        "Tools"
    );

    const TSharedRef<SWidget> MenuWidget = MenuBarBuilder.MakeWidget();

    ChildSlot
    [
        SNew(SBorder)
        .BorderImage(FCoreStyle::Get().GetBrush("ToolPanel.GroupBorder"))
        .BorderBackgroundColor(FLinearColor::Gray) // Darken the outer border
        [
            SNew(SVerticalBox)
            + SVerticalBox::Slot()
            .AutoHeight()
            .Padding(FMargin(0.0f, 4.0f, 0.0f, 0.0f))
            [
                MenuWidget
            ]
            + SVerticalBox::Slot()
            [
                SNew(SScrollBox)
                + SScrollBox::Slot()
                .VAlign(VAlign_Top)
                .Padding(5.0f)
                [
                    SNew(SToolkitMakerDemo)
                    //SNew(SBorder)
                    //.BorderBackgroundColor(FColor(192, 192, 192, 255))
                    //.Padding(15.0f)
                    //[
                    //    SNew(STextBlock)
                    //    .Text(FText::FromString(TEXT("This is a tab example.")))
                    //]
                ]
            ]
        ]
    ];
}

// Commands ===========================================================

void TabToolPanel::MapCommands()
{
    const auto& Commands = TabToolCommands::Get();

    CommandList->MapAction(
        Commands.NewCommand,
        FExecuteAction::CreateSP(this, &TabToolPanel::DefaultCommand),
        FCanExecuteAction());

    CommandList->MapAction(
        Commands.OpenCommand,
        FExecuteAction::CreateSP(this, &TabToolPanel::DefaultCommand),
        FCanExecuteAction());

    CommandList->MapAction(
        Commands.OpenRecentCommand,
        FExecuteAction::CreateSP(this, &TabToolPanel::DefaultCommand),
        FCanExecuteAction());

    CommandList->MapAction(
        Commands.SaveCommand,
        FExecuteAction::CreateSP(this, &TabToolPanel::DefaultCommand),
        FCanExecuteAction());

    CommandList->MapAction(
        Commands.SaveAsCommand,
        FExecuteAction::CreateSP(this, &TabToolPanel::DefaultCommand),
        FCanExecuteAction());

    CommandList->MapAction(
        Commands.QuitCommand,
        FExecuteAction::CreateSP(this, &TabToolPanel::DefaultCommand),
        FCanExecuteAction());
}

void TabToolPanel::DefaultCommand()
{
    UE_LOG(LogClass, Log, TEXT("Clicked Command Button"));
}

// Menu ===============================================================

void TabToolPanel::FillMenuPulldownMenu(FMenuBuilder& menuBuilder)
{
    // just a frame for tools to fill in
    menuBuilder.BeginSection("MenuSection", FText::FromString("Demo Menu"));
    menuBuilder.AddMenuEntry(TabToolCommands::Get().NewCommand);
    menuBuilder.AddMenuEntry(TabToolCommands::Get().OpenCommand);
    menuBuilder.AddSubMenu(
        FText::FromString("Open Recent"), 
        FText::GetEmpty(),
        FNewMenuDelegate::CreateSP(this, &TabToolPanel::MakeSubMenu)
    );
    menuBuilder.AddMenuEntry(TabToolCommands::Get().SaveCommand);
    menuBuilder.AddMenuEntry(TabToolCommands::Get().SaveAsCommand);
    menuBuilder.AddMenuSeparator(FName("Menu_Sep1"));
    menuBuilder.AddMenuEntry(TabToolCommands::Get().QuitCommand);
    menuBuilder.EndSection();
}

void TabToolPanel::MakeSubMenu(FMenuBuilder& menuBuilder)
{
    menuBuilder.AddMenuEntry(FText::FromString("some_file.h"), FText::GetEmpty(), FSlateIcon(), FUIAction(
        FExecuteAction::CreateSP(this, &TabToolPanel::ExecuteUIAction)
    ));
    menuBuilder.AddMenuEntry(FText::FromString("some_file.cpp"), FText::GetEmpty(), FSlateIcon(), FUIAction(
        FExecuteAction::CreateSP(this, &TabToolPanel::ExecuteUIAction)
    ));
    menuBuilder.AddMenuEntry(FText::FromString("some_file.xmp"), FText::GetEmpty(), FSlateIcon(), FUIAction(
        FExecuteAction::CreateSP(this, &TabToolPanel::ExecuteUIAction)
    ));
}

// Examples ===========================================================

void TabToolPanel::FillExamplesPulldownMenu(FMenuBuilder& menuBuilder)
{
    // just a frame for tools to fill in
    menuBuilder.BeginSection("ExamplesSection", FText::FromString("S1"));
    menuBuilder.AddMenuSeparator(FName("Examples_Sep1"));
    menuBuilder.EndSection();
}

// Tools ==============================================================

void TabToolPanel::FillToolsPulldownMenu(FMenuBuilder& menuBuilder)
{
    // just a frame for tools to fill in
    menuBuilder.BeginSection("ToolsSection", FText::FromString("S1"));
    menuBuilder.AddMenuSeparator(FName("Tools_Sep1"));
    menuBuilder.EndSection();
}

// UI Actions =========================================================

void TabToolPanel::ExecuteUIAction()
{
    UE_LOG(LogClass, Log, TEXT("Clicked UI Element"));
}

#undef LOCTEXT_NAMESPACE