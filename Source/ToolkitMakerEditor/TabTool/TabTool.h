#pragma once

#include "../TabToolBase.h"

class TabTool : public FTabToolBase
{
public:
    virtual ~TabTool() {}
    virtual void OnStartupModule() override;
    virtual void OnShutdownModule() override;
    virtual void Initialize() override;
    virtual TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs& TabSpawnArgs) override;
};