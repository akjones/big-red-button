require 'serialport'
require 'rake'

load File.expand_path 'Rakefile'

launch_code = "8iAWv1dVOywXNobylMid"

port_str = "/dev/tty.usbserial-A6008lLX"
baud_rate = 9600
data_bits = 8
stop_bits = 1
parity = SerialPort::NONE

sp = SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)

while true do
  line = ""
  c = sp.getc
  while c != "\n" do
    line << c
    c = sp.getc
  end

  if line == launch_code 
    puts "Launch codes received"
    Rake::Task["deploy"].invoke
    Rake::Task["deploy"].reenable
    sleep 1
  end 
end

sp.close
