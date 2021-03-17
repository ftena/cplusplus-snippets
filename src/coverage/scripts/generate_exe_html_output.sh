
echo "reset all execution counts to zero..."
lcov --directory ../exe/build/ --zerocounters
echo ""

echo "run exe..."
cd ../exe/build
./bar
cd -
echo ""

echo "capture coverage data..."
lcov --directory ../exe/build/ --capture --output-file output_exe/kernel.info
echo ""

echo "gen html..."
genhtml output_exe/kernel.info --output-directory output_exe/
echo ""

