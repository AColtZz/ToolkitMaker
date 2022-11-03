// Copyright (C) Abdulla Dönmez 2022. All Rights Reserved.


#include "SToolkitMakerDemo.h"
#include "SlateOptMacros.h"

/**
 * ToolkitMakerDemo v1.0
 * (Demo code)
 *
 * Newcomers, read the documentation within the GitHub page on how to setup ToolkitMaker.
 * Get the latest version at {Insert GitHub Link}
 *
 * The Demo code in this file is designed to be easy to copy-and-paste into your plugin/application!
 * 
 * You can find more information about specific classes that will be used here in the documentation.
 * Documentation SCompoundWidget UE5 https://docs.unrealengine.com/5.0/en-US/API/Runtime/SlateCore/Widgets/SCompoundWidget/
 * 
 * 
 */

#define LOCTEXT_NAMESPACE "SToolkitMakerDemo"

 //-----------------------------------------------------------------------------
 // [SECTION] Demo Content Text
 //-----------------------------------------------------------------------------

class DemoContent
{
public:
	DemoContent()
	{ }

	// Information
	FText Introdcution = LOCTEXT("Introduction", "ToolkitMaker says hello! v1.0.20221102");
	FText HelpTitle = LOCTEXT("HelpTitle", "Help");
	FText HelpBody = LOCTEXT("HelpBody", "ABOUT THIS DEMO:\n- Sections below are demonstrating many aspects of slate UI\n- The \"Examples\" menu above leads to more demo contents.\n- The \"Tools\" menu above gives access to: About Box, ....? and ....? .");
	FText HelpBody2 = LOCTEXT("HelpBody2", "PROGRAMMER GUIDE:\n- See the Construct() code in SToolkitMakerDemo.cpp.\n- See examples Widgets/ folder.");
	FText WidgetTitle = LOCTEXT("WidgetTitle", "Widget Gallery");

};

#undef LOCTEXT_NAMESPACE

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SToolkitMakerDemo::Construct(const FArguments& InArgs)
{
	TSharedPtr<DemoContent> demo = MakeShareable(new DemoContent());

	//-----------------------------------------------------------------------------
	// [SECTION] ExpendableArea Widget
	//-----------------------------------------------------------------------------

	TSharedRef<SWidget> helpHeader = TextBoxExample(demo->HelpTitle);

	TSharedRef<SWidget> helpContent = SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.HAlign(EHorizontalAlignment::HAlign_Fill)
		.VAlign(EVerticalAlignment::VAlign_Fill)
		.AutoHeight()
		[
			BorderWithTextExample(demo->HelpBody)
		]
		+ SVerticalBox::Slot()
		.HAlign(EHorizontalAlignment::HAlign_Fill)
		.VAlign(EVerticalAlignment::VAlign_Fill)
		.AutoHeight()
		[
			BorderWithTextExample(demo->HelpBody2)
		];

	TSharedRef<SWidget> widgetHeader = SNew(STextBlock)
		.Text(demo->WidgetTitle);

	TSharedRef<SWidget> widgetContent = WidgetGallery(demo.ToSharedRef());

	//-----------------------------------------------------------------------------
	// [SECTION] Widget Demo Panel
	//-----------------------------------------------------------------------------

	ChildSlot
	[
		// Populate the widget
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			[
				SNew(SScrollBox)
				+ SScrollBox::Slot()
				.HAlign(HAlign_Fill)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(FMargin(0, 10, 0, 10))
					[
						TextBoxExample(demo->Introdcution)
					]
					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(FMargin(0, 0, 0, 10))
					[
						ExpandableAreaExample(helpHeader, helpContent)
					]
					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(FMargin(0, 0, 0, 10))
					[
						ExpandableAreaExample(widgetHeader, widgetContent, false)
					]
				]
			]
		]
	];
}

//-----------------------------------------------------------------------------
// [SECTION] Widget Gallery
//-----------------------------------------------------------------------------

TSharedRef<SWidget> SToolkitMakerDemo::WidgetGallery(TSharedRef<DemoContent> demo)
{
	TSharedRef<SWidget> Widget = SNew(SVerticalBox)
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SBorder")), BorderExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SBreadcrumbTrail")), BreadCrumbExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SButton")), ButtonExample(FText::FromString("Button"), FText::FromString("Button ToolTip Text")))
			]
		+SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SButton (no content)")), ButtonExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SCheckBox")), CheckBoxExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SCheckBox (as radio buttons)")), CheckBoxRadioExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SCircularThrobber")), CircularThrobberExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SColorBlock")), ColorBlockExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SComboBox")), ComboBoxExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SComboButton")), ComboButtonExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SEditableText")), EditableTextExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SEditableTextBox")), EditableTextBoxExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SMultiLineEditableText")), MultiLineEditableTextExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SMultiLineEditableTextBox")), MultiLineEditableTextBoxExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SHeader")), HeaderExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SHyperlink")), HyperlinkExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SImage")), ImageExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SProgressBar")), ProgressBarExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SSearchBox")), SearchBoxExample())
			]
		+ SVerticalBox::Slot()
			.Padding(10.0f)
			.AutoHeight()
			[
				HorizontalBoxExample(TextBoxExample(FText::FromString("SSeparator")), SeparatorExample())
			]
		;
	
	return Widget;
}

//-----------------------------------------------------------------------------
// [SECTION] Example Widget Helpers
//-----------------------------------------------------------------------------

TSharedRef<SWidget> SToolkitMakerDemo::BorderExample()
{
	TSharedRef<SWidget> Widget = SNew(SBorder)
		.BorderImage(FAppStyle::Get().GetBrush("DetailsView.GridLine"))
		.Padding(FMargin(0, 0, 0, 10));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::ButtonExample(FText content, FText toolTip)
{
	if (content.IsEmpty())
	{
		// TODO: Figure out how empty button work!
		TSharedRef<SWidget> Widget = SNew(STextBlock)
			.Text(FText::FromString("TODO: Figure out how empty button work!"));

		return Widget;
	}

	TSharedRef<SWidget> Widget = SNew(SButton)
		.Text(content)
		.ToolTipText(toolTip)
		.ContentPadding(FMargin(10.0f, 5.0f));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::BreadCrumbExample()
{
	// TODO: Figure out how breadcrumbs work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how breadcrumbs work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::BorderWithTextExample(FText content)
{
	TSharedRef<SWidget> Widget = SNew(SBorder)
		.BorderImage(FAppStyle::Get().GetBrush("DetailsView.GridLine"))
		.Padding(FMargin(0, 0, 0, 10))
		[
			SNew(STextBlock)
			.Text(content)
		];

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::CheckBoxExample()
{
	// TODO: Figure out how checkbox work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how checkbox work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::CheckBoxRadioExample()
{
	// TODO: Figure out how checkbox radio buttons work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how checkbox radio buttons work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::CircularThrobberExample()
{
	// TODO: Figure out how circular throbber work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how circular throbber work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::ComboBoxExample()
{
	// TODO: Figure out how combobox work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how combobox work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::ComboButtonExample()
{
	// TODO: Figure out how combobutton work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how combobutton work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::EditableTextExample()
{
	// TODO: Figure out how editable text work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how editable text work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::EditableTextBoxExample()
{
	// TODO: Figure out how editable text box work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how editable text box work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::MultiLineEditableTextExample()
{
	// TODO: Figure out how multiline editable text work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how multiline editable text work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::MultiLineEditableTextBoxExample()
{
	// TODO: Figure out how multiline editable text work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how multiline editable text box work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::HeaderExample()
{
	// TODO: Figure out how header work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how header work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::HyperlinkExample()
{
	// TODO: Figure out how hyperlink work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how hyperlink work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::ImageExample()
{
	// TODO: Figure out how image work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how image work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::ProgressBarExample()
{
	// TODO: Figure out how progressbar work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how progressbar work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::SearchBoxExample()
{
	// TODO: Figure out how search work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how search work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::SeparatorExample()
{
	// TODO: Figure out how separator work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how separator work!"));

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::ExpandableAreaExample(TSharedRef<SWidget> headerContent, TSharedRef<SWidget> bodyContent, bool collapsed)
{
	TSharedRef<SWidget> Widget = SNew(SExpandableArea)
		.InitiallyCollapsed(collapsed)
		.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
		.Padding(5.0f)
		.HeaderContent()
		[
			headerContent
		]
		.BodyContent()
		[
			bodyContent
		];

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::TextBoxExample(FText content)
{
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(content);

	return Widget;
}

TSharedRef<SWidget> SToolkitMakerDemo::HorizontalBoxExample(TSharedRef<SWidget> leftContent, TSharedRef<SWidget> rightContent)
{
	TSharedRef<SWidget> Widget = SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.Padding(FMargin(0, 0, 10, 0))
		.HAlign(HAlign_Left)
		[
			leftContent
		]
		+SHorizontalBox::Slot()
		.Padding(FMargin(10, 0, 0, 0))
		.AutoWidth()
		.HAlign(HAlign_Left)
		[
			rightContent
		];

	return Widget;
}

//-----------------------------------------------------------------------------
// [SECTION] Color Widget
//-----------------------------------------------------------------------------

TSharedRef<SWidget> SToolkitMakerDemo::ColorsExample()
{
	// TODO: Figure out how color block work!
	TSharedRef<SWidget> Widget = SNew(STextBlock)
		.Text(FText::FromString("TODO: Figure out how colors work!"));

	return Widget;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
