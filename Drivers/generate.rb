#!/usr/bin/env ruby
#ищем OS= в makdefs файле

def getFieldFromFile( file, name)
File.open(file,"r") do |f| # ищем name =
        f.each do |line|
            if line.strip.index(name) == 0 then
                l=line.split("=")
                  return l[1].strip if l[0].strip == name
                             end
                             end
                             end
                             return ""
                                    end

                                    @ACEOS=getFieldFromFile("../makdefs", "OS")
                                           p @ACEOS

                                           @exceptlist=[]  #список исключений

                                                       File.open("exceptions","r") do |f| #формируем список исключений
                                                           f.each do |line|
                                                               l=line.strip
                                                                       unless (l.empty?) then
                                                                       @exceptlist.push(l) unless l[0,1] == '#'
                                                                       end
                                                                       end
                                                                       end

                                                                       def mustexclude(nn) #проверка есть ли имя nn в списке исключений
                                                                       @exceptlist.each do |l|
                                                                           return true if l == nn
                                                                                   end
                                                                                   return false
                                                                                           end

                                                                                           p @exceptlist , "-> must excluded" unless @exceptlist.empty?

                                                                                           subdirs = [] #это наши директории с драйверами
                                                                                                       ssdirs =[] # временный список
                                                                                                               Dir.new('.').each do |d| # формируем список и удаляем исключения
                                                                                                                   ssdirs.push(d) unless d == '.' or d == '..' or d == '.svn' if File.stat(d).directory? and not mustexclude(d)
                                                                                                                       end
                                                                                                                       subdirs = ssdirs.sort

                                                                                                                               p subdirs , "-> was generated" unless subdirs.empty?

                                                                                                                               includeText=[]
                                                                                                                                       declaredrivers = "#define ISA_DECLARE_DRIVERS "

                                                                                                                                               libText=[]
                                                                                                                                                       drvlib="DRVLIB="

                                                                                                                                                               descText=["This ISaGRAF Target contains the following functional extensions:
                                                                                                                                                                       "]

                                                                                                                                                                       tdbText=[]

                                                                                                                                                                               subdirs.each do |d| #идем по правильным директориям
                                                                                                                                                                                   hFile = File.join(d, "pack_" + d + ".h")
                                                                                                                                                                                           if File.stat(hFile).readable? then #формируем инклюды
                                                                                                                                                                                               includeText.push("#include \"" + hFile + "\"")
                                                                                                                                                                                               declaredrivers += " ISA_DECLARE_PACK_" + d.upcase
                                                                                                                                                                                                       end

                                                                                                                                                                                                       libFile=File.join(d, "libdefs.inc")
                                                                                                                                                                                                               if FileTest.exist?(libFile) && File.stat(libFile).readable? then #формируем либдефсы
                                                                                                                                                                                                                   libText.push("include ../Drivers/" + libFile)
                                                                                                                                                                                                                   end
                                                                                                                                                                                                                   drvlib += "$(LDIR)/lib" + d + ".a "

                                                                                                                                                                                                                           descText.push("* " + d + " driver:")
                                                                                                                                                                                                                           txtFile=File.join(d, "description.txt")
                                                                                                                                                                                                                                   if FileTest.exist?(txtFile) && File.stat(txtFile).readable? then #формируем комментарии
                                                                                                                                                                                                                                       descTemp=IO.readlines(txtFile)
                                                                                                                                                                                                                                               for i in 0..descTemp.length
                                                                                                                                                                                                                                               descTemp[i]="\t" + descTemp[i] if descTemp[i]
                                                                                                                                                                                                                                                               end
                                                                                                                                                                                                                                                               descText.push(descTemp)
                                                                                                                                                                                                                                                               end

                                                                                                                                                                                                                                                               tdbFile=File.join(d, d + ".tdb")
                                                                                                                                                                                                                                                                       if File.stat(tdbFile).readable? then #формируем TDB
                                                                                                                                                                                                                                                                           tdbText.push(IO.readlines(tdbFile))
                                                                                                                                                                                                                                                                           end
                                                                                                                                                                                                                                                                           end #все - прошли по правильным директориям
#теперь запишем в файлы что сформировано

                                                                                                                                                                                                                                                                           File.open("Drivers.h","w") do |hf|
                                                                                                                                                                                                                                                                               hf.puts(includeText)
                                                                                                                                                                                                                                                                               hf.print(declaredrivers)
                                                                                                                                                                                                                                                                               end

                                                                                                                                                                                                                                                                               File.open("libdefs","w") do |hf|
                                                                                                                                                                                                                                                                                   hf.puts(libText)
                                                                                                                                                                                                                                                                                   hf.print(drvlib)
                                                                                                                                                                                                                                                                                   end

                                                                                                                                                                                                                                                                                   File.open("../Cmds/drvset.txt","w") do |hf|
                                                                                                                                                                                                                                                                                       hf.puts(descText)
                                                                                                                                                                                                                                                                                       end

                                                                                                                                                                                                                                                                                       File.open("drivers.tdb","w") do |hf|
                                                                                                                                                                                                                                                                                           hf.puts(tdbText)
                                                                                                                                                                                                                                                                                           end

                                                                                                                                                                                                                                                                                           p "Done"

