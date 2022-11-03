# Toolkitmaker UE5

"To be added quick intro!"

***

| <div align="center">[The Pitch](#the-pitch) - [Installation](#installation) - [What's Next](#whats-next)</div> |
|----------------------------------------------------------|
| <div align="center">[How to Help](#how-to-help) - [Credits](#credits) - [Licence](#licence)</div> |
| <div align="center">[Wiki](https://github.com/AColtZz/ToolkitMaker/wiki)</div> |

***

# The Pitch

This plugin is here to help you kick off tool creation within Unreal Engine 5 by making use of Slate UI. Slate is a completely custom and platform agnostic user interface framework that is designed to make building the user interfaces for tools and applications such as Unreal Editor, or in-game user interfaces, fun and efficient. It combines a declarative syntax with the ability to easily design, lay out, and style components that allows for easily creating and iterating on UIs.

The Slate UI solution makes it extremely easy to put together graphical user interfaces for tools and applications and iterate on them quickly.

***

# Installation

1. Download the latest release.
2. Create a new project in Unreal and navigate to the project folder (Project)
3. Extract the plugin into the "Plugins" folder within the project
4. open the Project > Source > {ProjectName}Editor.Target.cs file
5. Add the following (choose either the .AddRange or .Add):
```
ExtraModuleNames.AddRange( new string[] { "{ProjectName}", "ToolkitMakerEditor" } );

ExtraModuleNames.Add("{ProjectName}");
ExtraModuleNames.Add("ToolkitMakerEditor");
```

More in-depth information can be found in the [Wiki](https://github.com/AColtZz/ToolkitMaker/wiki)

***

# Screenshots

![Screenshot1](https://github.com/AColtZz/ToolkitMaker/blob/master/Resources/GitHub/screenshot1.png)

![Screenshot2](https://github.com/AColtZz/ToolkitMaker/blob/master/Resources/GitHub/screenshot2.png)

![Screenshot3](https://github.com/AColtZz/ToolkitMaker/blob/master/Resources/GitHub/screenshot3.png)

***

# What's Next

So, currently u can find a lot of sources in this tutorial to other places where you can find really useful information on your journey to creating tools. Feel free to get this plugin and drop it in your project to explore the different functionalities (open for suggestions) for your future tools. This demo should serve as a starter’s guide and hopefully be enough. 

Feel free to leave suggestions that can be added to the list below. Would like to create a nice list and make this GitHub repo a place where people can make commits/contributions to while exploring a new side of UI in Unreal.

## Possible Future Topics:
* Tools/Small Features
  * Change Object Material Colour(s).
  * Get Object Details Into a custom panel.
* Customize Details Panel
* Custom Data Type
* Custom Editor Mode
* Custom Project Settings

***

# How to help
How can I help?

* See [GitHub Forum/Issues](https://github.com/AColtZz/ToolkitMaker/issues) and [GitHub Discussions](https://github.com/AColtZz/ToolkitMaker/discussions).
* You may help with development and submit pull requests! Please understand that by submitting a PR you are also submitting a request for the maintainer to review your code. PR should be crafted both in the interest of the end-users and also to ease the maintainer into understanding and accepting it.
* See post ideas in the discussion category [Discussions Ideas](https://github.com/AColtZz/ToolkitMaker/discussions/categories/ideas)
* 

***

# Credits

Developed by [Abdulla Donmez](http://abdulladonmez.com/) and every direct or indirect [contributors](https://github.com/AColtZz/ToolkitMaker/graphs/contributors) to the GitHub.

Abdulla: “My first experiences with Slate UI in Unreal 5, this project started as a self-study topic. However as time passed by and I started working on these examples, diving into engine code for slate snippets. And not finding many tutorials online. I wanted to create this GitHub project. Where everyone could contribute and maybe create a cool base for newer users who get into slate programming to start off really fast.“

***

# Licence

Toolkitmaker is licensed under the MIT License, see [LICENSE.md](https://github.com/AColtZz/ToolkitMaker/blob/master/LICENSE.md) for more information.
