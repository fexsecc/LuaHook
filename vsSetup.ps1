#go into the build directory
cd build

dotnet sln luahook.sln remove ALL_BUILD.vcxproj
dotnet sln luahook.sln remove ZERO_CHECK.vcxproj

#cd to the original directory
cd ..
