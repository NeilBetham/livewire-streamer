livewire-streamer
=================

Stream a Livewire multicast stream to Icecast


Setup
=====
* Small Ubuntu VM, you can prolly get away with 1 core
* FFMpeg installed with MP3 support
* EZStream installed

1. Edit stream.conf with your specific details
2. Copy stream.conf
3. $ start stream
4. ???
5. Profit!

Configuration
=============
* Output formatting
 * avconv -f s24be -ar 48k -ac 2 -i - -f mp3 -b:a 320K -
 * -f mp3 | Change that to the format you want to stream
 * -b:a 320K | Change 320K to the bit rate you want to broadcast in
