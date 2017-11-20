livewire-streamer
=================
This is a simple Ubuntu upstart script that runs some utilities to pipe audio from a Livewire network 
to an instance of Icecast.

* Livewire is a protocol used in the broadcast industry to stream CD quality audio over a network.


Setup
=====
* Small Ubuntu VM on your Livewire network, I used 14.04, you can prolly get away with 1 core if you run server edition
* `> apt-get install libav-tools ezstream dvbstream`
 * `libav-tools` for avconv utility, make sure it's installed with MP3 support
 * `ezstream` for streaming to icecast
 * `dvbstream` for the dumptrp utility


1. Use ftp://ftp.zephyr.com/pub/Axia/Tools/sdpgen.htm to get the multicast IP for your channel number
 * The line "c=IN IP4 239.192.0.203" has the ip you need
2. Edit stream.conf with your specific conversion/ip details
3. Edit ezstream.xml with your icecast details
4. If you are on Ubuntu 16.04, go to the directions below
5. Copy stream.conf to /etc/init/Unless you are running 16.04 in which case checkout the directions below
6. `> start stream`
7. ???
8. Profit!

## Ubuntu 16.04 Systemd Configuration
For Ubuntu 16.04 the init system was switch from Upstart to Systemd. As such you will need to use the example
`livewire-streamer.service` Systemd unit file instead of the upstart conf file.

1. Copy the `livewire-stream.service` to `/etc/systemd/system/`
2. `> systemctl daemon-reload`
3. `> systemctl enable livewire-streamer.service`
4. `> systemctl start livewire-streamer.service`
5. ???
6. Profit!

Your streaming process should be up and running, this can be checked with `systemctl status livewire-streamer.service`


Configuration
=============
#### Output formatting
* `avconv -f s24be -ar 48k -ac 2 -i - -f mp3 -b:a 320K -` This portion of the command transcodes the audio 
  * `-f mp3` Change that to the format you want to stream / output, Check avconv -formats for output codecs
  * `-b:a 320K` Change 320K to the bit rate you want to stream

Troubleshooting
===============
* If the stream upstart job doesn't stay running check /var/log/upstart/stream for errors
