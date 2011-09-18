# xmonad-log-applet

xmonad-log-applet is for Xmonad users who find the GNOME panel useful. The
applet will show the active workspaces, the title of the selected window or
whatever information you send it from your xmonad.hs.

xmonad-log-applet was originally written by Adam Wick, you can get more details
on the [old website][0].

## Installation

There are two pieces of setup you'll need to get this working, assuming you are
already running [Xmonad within GNOME][1]:

* An xmonad.hs setup file that will send properly-formatted information to
  D-Bus. You can use [this xmonad.hs][2] as an example; obviously, feel free to
  change the colours to match your tastes.

* The panel applet. You can either get the current stable build as a
  [tarball][3], or pull the latest version from the git repository: `git clone
  git://github.com/alexkay/xmonad-log-applet.git`

The applet supports both GNOME 2 and GNOME 3 panels, just pass
`--with-panel=gnomeX` to `./configure` when compiling.


## Contact

If you have any questions, comments or bug reports, please contact me via GitHub
or drop me a line at <alexander@kojevnikov.com>.

[0]: http://uhsure.com/xmonad-log-applet.html
[1]: http://www.haskell.org/haskellwiki/Xmonad/Using_xmonad_in_Gnome
[2]: https://github.com/alexkay/xmonad-log-applet/blob/master/xmonad.hs
[3]: https://github.com/downloads/alexkay/xmonad-log-applet/xmonad-log-applet-1.0.4.tar.gz
