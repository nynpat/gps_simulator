make clean
echo "Cleared alll old files"
make all
echo "gpssimulation application compiled successfully"
cp `pwd`/build/samples_generate ~/../../media/sf_Desktop/gps_v2.0
cp `pwd`/build/samples_generate /tftpboot/gps_v2.0
cp `pwd`/build/samples_generate ./gps_v2.0
echo "gps_v2.0 application moved to tftpboot folder"
