# Sofle_Split_Keyboard_Mod_Firmware
This is MOD frmware of Sofle Split Keyboard

## Table of Content
* [Product Specsification](#product-specsification)
* [Download VIA](#download-via)
* [Load JSON File](#Load-JSON-File)
* [Link Keycode QMK](#Link-keycode-qmk)
* [Tutorial VIA Usage](#tutorial-via-usage)
* [Cara Setting Knob](#cara-setting-knob)
* [How To use MACRO](#how-to-use-macro)
* [Preview Hardware](#preview-hardware)
* [Preview VIA](#preview-via)
* [Cara Update/Upgrade Firmware](#cara-update/upgrade-firmware)
* [Documentation](#documentation)
  * [Pinout Diagram](#pinout-diagram)
  * [Dimension](#dimension)
  * [BOM](#bom)
  * [Schematic](#schematic)
  * [Example Program](#examples-program)
* [FAQ](#FAQ)

## Product Specsification
- Arduino Pro Micro Type C as Microcontroller
- QMK Firmware
- Support VIA, all key and knob can proggrammed
- RGB Underglow
- 4x Layer 
- Hotswap Switch
- 3D Case 
- Sofle Profile

## Download VIA
Link Download VIA(CHOSEE BASED YOUR OS) : https://github.com/the-via/releases/releases
VIA WEB VERSION : https://usevia.app/


## Autodetect VIA
You can connect keyboard to the PC and open VIA on WEB or APPS

## Link Keycode QMK
- mouse : https://github.com/qmk/qmk_firmware/blob/master/docs/feature_mouse_keys.md
- keyboard : https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

## Tutorial VIA Usage
- https://docs.keeb.io/via

## Cara Setting Knob
- Untuk melakukan setting di knob perlu memasukan command berupa keycode qmk, Jadi cara nya sama dengan melakuykan setting dengan Any key seperti petunjuk pada link berikut: 
https://docs.keeb.io/via

Here's some examples:

- LALT(KC_TAB) - Sends Alt-Tab
- LCTL(KC_C) - Sends Ctrl-C
- LGUI(KC_C) - Sends Cmd-C or Win-C
- LSFT(LCTL(KC_END)) - Sends Shift-Ctrl-End
- MO(1) - Momentarily turn on layer 1
- LCA(KC_DEL) - Sends Ctrl-Alt-Del
- MT(MOD_RSFT, KC_ENT) - Sends Shift if held, Enter if tapped
- MACRO (0) - macro 0

## How To use MACRO
you can read on [this file](https://github.com/juarendra/STREAMPAD-QMK-VIA/blob/main/DOC/MACRO%20VIA%20USAGE.pdf)
or you can read on this [web](https://www.keychron.com/blogs/archived/how-to-use-via-to-program-your-keyboard)
or you can see video [youtube](https://youtu.be/GtSeo69Y0Zw)

## Preview Hardware
<p align="center">
  <img src="DOC/HARDWARE/sofle2.jpeg" width="50%" height="50%">
  <img src="DOC/HARDWARE/sofle4.jpeg" width="50%" height="50%">
  <img src="DOC/HARDWARE/sofle1.jpeg" width="50%" height="50%">
</p>

## Preview VIA

https://github.com/juarendra/Zeapad-Pro-QMK-VIA/assets/43043633/afd7e68e-0a54-4b18-be12-b96c0f13611a

## Cara Compile Firmware
pada folder new_sofle terdapat 2 keymaps, Copy semua isi folder tersebut ke folder qmk_firmware/keyboard/sofle

**VIA Keymaps**
keymaps ini adalah keymaps yang normal digunakan dengan feature seperti berikut
- VIA enable
- RGB underglow Enable
- Encoder Map Enbale
- Mouse Key disable
- Macro 16
- layer 4
- OLED standar with logo yin and yang
- WPM display on OLED

**Pet Keymaps**
- VIA enable
- RGB underglow Disable 
- Encoder Map Enbale
- Mouse Key disable
- Macro 16
- layer 4
- OLED PET with interaktif with wpm

Buka QMK-MYSYS
Buka folder qmk
lakukan flash sesuai dengan keymaps yang anda ingin gunakan dengan perintah berikut
```sh
    qmk compile -kb sofle/rev1 -km via
```

## Cara Update/Upgrade Firmware
- Siapkan dahulu Keyboard sofle, kabel usb dan firmware yang ingin di update/upgrade ke keyboard anda anda
- Anda perlu melakukan flashing di masing masing sisi keyboard (kanan dan kiri)
- Siapkan Firmware yang akan digunakan untuk update/upgrade
- Download Software QMK Toolbox di [link berikut](https://github.com/qmk/qmk_toolbox/releases)
- Install Software QMK Toolbox, Install Semua drivernya. setelah siap anda dapat meload Firmware yang seblumnya. Lalu Centang Auto-Flash seperti gambar dibawah
<p align="center">
  <img src="DOC/QMK Tollbox Awal.PNG" width="50%" height="50%">
</p>

- Lakukan flashing pada sisi kiri dahulu
- Pada Sofle sisi kiri Colok kabel ujung usb type C ke keyboard tanpa mencolokannya dahulu ke USB PC anda
- Tekan dan tahan tombol yang berada di ujung atas kiri. lalu colokan Ujung USB yang sebelum ke USB PC anda sambil tetap menahan tombol sebelum nya sebentar
- Setelah ada bunyi/notif USB masuk. anda dapat melepaskan tombol/knobnya
- Maka secara otomatis macropad akan terflash. jika selesai maka tampilan QMK toolbox akan seperti gambar dibawah
<p align="center">
  <img src="DOC/Selesai Flash QMK Toolbox.PNG" width="50%" height="50%">
</p>

- Lakukan flashing pada sisi kanan
- Pada Sofle sisi kanan Colok kabel ujung usb type C ke keyboard tanpa mencolokannya dahulu ke USB PC anda
- Tekan dan tahan tombol yang berada di ujung atas kanan. lalu colokan Ujung USB yang sebelum ke USB PC anda sambil tetap menahan tombol sebelum nya sebentar
- Setelah ada bunyi/notif USB masuk. anda dapat melepaskan tombol/knobnya
- Maka secara otomatis macropad akan terflash. jika selesai maka tampilan QMK toolbox akan seperti gambar dibawah
<p align="center">
  <img src="DOC/Selesai Flash QMK Toolbox.PNG" width="50%" height="50%">
</p>

## Documentation
### Pinout Diagram
### Dimension
[Dimension File](https://github.com/juarendra/Sofle_Split_Keyboard_Mod_Firmware/blob/main/HARDWARE/dimension_sofle.pdf)
### BOM
### Schematic
[Schematic File](https://github.com/juarendra/Sofle_Split_Keyboard_Mod_Firmware/blob/main/HARDWARE/schematic.pdf)
### Example Program
[Example Firmware](https://github.com/juarendra/Sofle_Split_Keyboard_Mod_Firmware/tree/main/FIRMWARE)
## FAQ
