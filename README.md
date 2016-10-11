livewire-streamer
=================
This is a c program which can be used to stream a Livewire audio source to an icecast server

* Livewire is a protocol used in the broadcast industry to stream CD quality audio over a network.


Setup
=====
* Small Ubuntu VM on your Livewire network, I used 14.04, you can prolly get away with 1 core if you run server edition
* `> apt-get install libav libshout`
 * `libav` __Note__ Make sure it's installed with MP3 support
 * `libshout` For connecting to icecast 
 * `libortp` For decoding RTP streams

1. Directions to follow once something is working

Configuration
=============
  * Need to code some ish first

Troubleshooting
===============
  * No code == No troubleshooting
