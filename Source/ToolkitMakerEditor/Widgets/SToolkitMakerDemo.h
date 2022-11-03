// Copyright (C) Abdulla Dönmez 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Slate.h" // Includes, SlateBasics.h / SlateExtras.h

class DemoContent;
class SToolkitMakerDemo : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SToolkitMakerDemo)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

protected:
	TSharedRef<SWidget> BorderWithTextExample(FText content);
	TSharedRef<SWidget> ExpandableAreaExample(TSharedRef<SWidget> header, TSharedRef<SWidget> body, bool collapsed = true);
	TSharedRef<SWidget> HorizontalBoxExample(TSharedRef<SWidget> leftContent, TSharedRef<SWidget> rightContent);
	TSharedRef<SWidget> TextBoxExample(FText content);
	TSharedRef<SWidget> WidgetGallery(TSharedRef<DemoContent> demo);
	TSharedRef<SWidget> BorderExample();
	TSharedRef<SWidget> ButtonExample(FText content = FText::GetEmpty(), FText toolTip = FText::GetEmpty());

	TSharedRef<SWidget> ColorsExample();

	TSharedRef<SWidget> BreadCrumbExample();
	TSharedRef<SWidget> CheckBoxExample();
	TSharedRef<SWidget> CheckBoxRadioExample();
	TSharedRef<SWidget> CircularThrobberExample();
	TSharedRef<SWidget> ComboBoxExample();
	TSharedRef<SWidget> ComboButtonExample();
	TSharedRef<SWidget> EditableTextExample();
	TSharedRef<SWidget> EditableTextBoxExample();
	TSharedRef<SWidget> MultiLineEditableTextExample();
	TSharedRef<SWidget> MultiLineEditableTextBoxExample();
	TSharedRef<SWidget> HeaderExample();
	TSharedRef<SWidget> HyperlinkExample();
	TSharedRef<SWidget> ImageExample();
	TSharedRef<SWidget> ProgressBarExample();
	TSharedRef<SWidget> SearchBoxExample();
	TSharedRef<SWidget> SeparatorExample();
};
