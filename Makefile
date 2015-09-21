
.PHONY: all drivers isavm clean
################################################################################

all: drivers isavm finish
drivers:
	echo "***** Make drivers *****"
	make -C ./Drivers

isavm:
	echo 
	echo "***** Build IsaVM *****"
	make -C ./IsaVm

clean:
	make -C ./Drivers clean
	make -C ./IsaVm clean

finish:
	echo
	echo "***************************** Finished ***********************************"
