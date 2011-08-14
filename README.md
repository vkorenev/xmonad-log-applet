# Xmonad, GNOME Panel and xmonad-log-applet

xmonad-log-applet is for Xmonad users who find the GNOME panel useful. The applet will show the active workspaces, the title of the selected window or whatever information you send it from your xmonad.hs.

## Technical Overview

[Xmobar][2] utilises logging information from Xmonad to display its state. When you use Xmobar, this information is passed to Xmobar using stdin. This works because typically Xmobar is launched from your Xmonad configuration script, so its fairly easy to wire the pipes together. However, gnome-panel typically starts before or concurrently with Xmonad, so this same trick won't work.

Fortunately, [D-Bus][3] provides almost exactly the service we want. D-Bus is a messaging mechanism by which one application can send messages to another application running on the same computer. In this case, we will set up Xmonad to send messages to our display applet.

That's pretty much it; it was actually pretty easy. First, we set up Xmonad to transmit its log messages through D-Bus. Then, we create a little GNOME applet to read these messages and display them to the screen.

## Installation

There are two pieces of setup you'll need to get this working, assuming you are [already running Xmonad within GNOME][4]:

* An xmonad.hs setup file that will send properly-formatted information to D-Bus. You can use [this xmonad.hs][5] as an example; obviously, feel free to change the colours to match your tastes.

* The Xmonad Log Display Widget. You can either get the [current stable build as a tarball][6], or pull the latest version from the git repository: `git clone git://github.com/alexkay/xmonad-log-applet.git`

## Contact

If you have any questions, comments, or bug reports for this software, please contact me via GitHub or drop me a line at alexander at kojevnikov dot com.

[1]: https://github.com/alexkay/xmonad-log-applet
[2]: http://gorgias.mine.nu/xmobar/
[3]: http://www.freedesktop.org/wiki/Software/dbus
[4]: http://www.haskell.org/haskellwiki/Xmonad/Using_xmonad_in_Gnome
[5]: https://github.com/alexkay/xmonad-log-applet/blob/master/xmonad.hs
[6]: https://github.com/downloads/alexkay/xmonad-log-applet/xmonad-log-applet-1.0.3.tar.gz
