#pragma once

#include "Framework/Application/SlateApplication.h"
//#include "Widgets/Docking/SDockTabStack.h" Not found in UE5
//#include "Widgets/Docking/SDockableTab.h" Not found in UE5
#include "Widgets/Docking/SDockTab.h"
#include "TabTool.h"

class TabToolPanel : public SCompoundWidget
{
    SLATE_BEGIN_ARGS(TabToolPanel)
    { }
    SLATE_ARGUMENT(TWeakPtr<class TabTool>, Tool)
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);

protected:
    TWeakPtr<TabTool> tool;

    void FillMenuPulldownMenu(FMenuBuilder& menuBuilder);
    void FillExamplesPulldownMenu(FMenuBuilder& menuBuilder);
    void FillToolsPulldownMenu(FMenuBuilder& menuBuilder);

    void MakeSubMenu(FMenuBuilder& menuBuilder);
    
    TSharedPtr<FUICommandList> CommandList;

    void MapCommands();
    // UI Command functions (New, Open, etc.)
    void DefaultCommand();
    // UI Action functions (Opening A File...)
    void ExecuteUIAction();

private:
    TSharedPtr<FTabManager> TabManager;

};