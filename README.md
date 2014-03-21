livewire-streamer
=================

Stream a Livewire multicast stream to Icecast


Setup
=====
* Small Ubuntu VM on your Livewire network, I used 13.10, you can prolly get away with 1 core if you run server edition
* ffmpeg installed with MP3 support
* ezstream installed
* dumprtp installed

1. Use http://axiaaudio.com/axia-livewire-sdp-generator-version-1-0 to get the multicast IP for your channel number
 * The line "c=IN IP4 239.192.0.203" has the ip you need
2. Edit stream.conf with your specific conversion/ip details
3. Edit ezstream.xml with your icecast details
4. Copy stream.conf to /etc/init/
5. $ start stream
6. ???
7. Profit!

Configuration
=============
* Output formatting
 * avconv -f s24be -ar 48k -ac 2 -i - -f mp3 -b:a 320K -
 * -f mp3 | Change that to the format you want to stream
 * -b:a 320K | Change 320K to the bit rate you want to broadcast in
