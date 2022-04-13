# Planck Layout

## Notes
Install qmk via homebrew
brew install qmk/qmk/qmk

After installing qmk provide some default settings
cd ~/Projects/keyboard/qmk_firmware/keyboards/planck/keymaps/
`qmk setup gunnarvoet/qmk_firmware`
`qmk config user.keymap=gunnarvoet`
`qmk config user.keyboard=planck/rev6`

-> modify keymap.c

make a json version (can be used in those online configurators)
`qmk c2json -kb planck/rev6 -km test keymap.c > current.json`

`qmk compile`
`qmk flash`
-> then on the layer where volume etc press q to put the keyboard into flash mode

make nice ascii keymap (https://github.com/yskoht/keymapviz)
`pip install keymapviz`
`keymapviz -c keymapviz.config.properties -t fancy keymap.c > current_map_ascii`
