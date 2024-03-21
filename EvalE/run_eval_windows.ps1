if(Test-Path -path .\build\){
    Remove-Item .\build\ -Force -Recurse
}
if(Test-Path -path .\q1.out){
    Remove-Item .\q1.out
}
if(Test-Path -path .\q2.out){
    Remove-Item .\q2.out
}
mkdir build
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
.\build\test\q1_test >> q1.out
.\build\test\q2_test >> q2.out
