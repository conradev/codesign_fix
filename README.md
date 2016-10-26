# codesign_fix

This tweak exists to work around [this](https://forums.developer.apple.com/thread/66418) issue.

## Installation

You will need to [disable](http://www.imore.com/el-capitan-system-integrity-protection-helps-keep-malware-away) System Integrity Protection in order for this to work.

**Install at your own risk** :smiley::

```sh
$ git clone https://github.com/conradev/codesign_fix.git
$ cd codesign_fix
$ make
$ sudo mv /usr/bin/codesign /usr/bin/codesign_old
$ sudo ln -s $PWD/codesign /usr/bin/codesign
```

To uninstall, undo the changes made above:

```sh
$ sudo rm /usr/bin/codesign
$ sudo mv /usr/bin/codesign_old /usr/bin/codesign
$ make clean
```
