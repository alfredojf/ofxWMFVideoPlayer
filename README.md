> Note: This repository supposed to be the merge of the latest stable implementation merged with forks where non-nvidia cards are also supported!

ofxWMFVideoPlayer
========================

This addon is an accelerated video player using the Windows Media Foundation API.
It was developed by Philippe Laulheret for [Second Story] (http://www.secondstory.com) and is released under MIT licensing. See license.md for more details.
For a more comprehensive/technical description of the work, please refer to the file TechnicalDescription.md

This addons is meant to work with openFrameworks 0.9 and superior, on windows Vista and following.
Previous version of oF could work as well but won't be maintained.

##Prerequisites

This addons uses the WGL_NV_DX_interop extension, or falls back to CPU copy (but still accelerated).
Since openFrameworks 9.0+, there is no need to upgrade the GLEW library!

On top of that this addon is built against the Direct X SDK of June 2010. At the time of writing, you can download it on the [Microsoft website](http://www.microsoft.com/en-us/download/details.aspx?id=6812)
For running, the only needed library is the latest production version of Direct X 9!

##Troubleshooting

In some instance we have noticed that the video appears "washed out". If you are noticing this it is due to a NVIDIA card setting that sets colors to a limited range of 16-235. You can fix this by doing the following:

* Open the nVidia Control Panel
* Adjust Video Color Settings
* Make Color Adjustments
* With nVidia Settings
* Select Advanced Tab
* Set Dynamic Range to: Full (0-255)