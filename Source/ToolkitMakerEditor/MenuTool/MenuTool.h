#pragma once

#include "../IToolkitMakerModuleInterface.h"

class MenuTool : public IToolkitMakerModuleListenerInterface, public TSharedFromThis<MenuTool>
{
public:
    virtual ~MenuTool() {}

    virtual void OnStartupModule() override;
    virtual void OnShutdownModule() override;

    void MakeMenuEntry(FMenuBuilder& menuBuilder);
    void MakeSubMenu(FMenuBuilder& menuBuilder);

    FReply AddTag();
    FText GetTagToAddText() const;
    TSharedRef<SWidget> AddTagWidget();
    void OnTagToAddTextCommited(const FText& InText, ETextCommit::Type CommitInfo);

public:
    FName TagToAdd;
    
protected:
    TSharedPtr<FUICommandList> CommandList;

    void MapCommands();

    // UI Command functions
    void MenuCommand1();
    void MenuCommand2();
    void MenuCommand3();
};