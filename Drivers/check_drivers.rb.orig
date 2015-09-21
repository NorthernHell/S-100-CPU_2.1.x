#!/usr/bin/env ruby
require 'fileutils'

#проверим Drivers.h libdefs drivers.tdb
@drvnew=false
begin
File.open('generating') {|mark| #проверяем новизну
  ddlist = ['Drivers.h', 'libdefs', 'drivers.tdb']
  ddlist.each { |item|
      if FileTest.exist?(item) and File.stat(item).readable? then #сравним на новизну
        newfile = mark.stat <=> File.stat(item)
        if newfile < 0
          @drvnew=true
          break
        end
      else # no file
          @drvnew=true
          break
      end
  }
}
rescue
  @drvnew=true
end

subdirs = [] #это наши директории с драйверами
ssdirs =[] # временный список
Dir.new('.').each do |d| # формируем список
  ssdirs.push(d) unless d == '.' or d == '..' or d == '.svn' if File.stat(d).directory?
end
subdirs = ssdirs.sort

#p subdirs , "-> was generated" unless subdirs.empty?

@olddirs = [] #это наши сохраненные директории с драйверами
begin
  File.open('drivers.list','r'){|rsave|
    @olddirs= Marshal.load(rsave)
  }
rescue
end

@hasnew = false
begin
File.open('generating') {|mark| #проверяем новизну
  subdirs.each do |d| #идем по директориям драйверов
    files = ["pack_" + d + ".h","libdefs.inc","description.txt",d + ".tdb"]
    files.each { |f|  
      hFile = File.join(d,f )
      if FileTest.exist?(hFile) and File.stat(hFile).readable? then #сравним на новизну
        newfile = mark.stat <=> File.stat(hFile)
        if newfile < 0
          @hasnew=true
          break
        end
      end
    }
 end
}
rescue
end

if not @drvnew and @olddirs == subdirs and not @hasnew
  p 'Old drivers'
else
  p 'New libdefs' if @drvnew
  p 'New drivers dir' if @olddirs != subdirs
  p 'New file in drivers dir ' if @hasnew

  
  FileUtils.rm_f 'generating'

  File.open('drivers.list','w'){|wsave|
  Marshal.dump(subdirs, wsave)
  }
end

