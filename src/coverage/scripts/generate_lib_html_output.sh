
echo "reset all execution counts to zero..."
lcov --directory ../lib/build/ --zerocounters
echo ""

echo "run bin..."
cd ../bin/build
./bar
cd -
echo ""

echo "capture coverage data..."
lcov --directory ../lib/build/ --capture --output-file output_lib/kernel.info
echo ""

echo "gen html..."
genhtml output_lib/kernel.info --output-directory output_lib/
echo ""
