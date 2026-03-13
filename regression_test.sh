#!/bin/bash
set -e

# Build the project
mkdir -p build
cd build
cmake ..
make -j$(nproc)

# Run the solver
ln -sf ../input.txt .
./extrapolation_solver

# Compare with baseline (ignoring small floating point differences)
# We can use a simple diff or a more sophisticated tool if needed.
# For now, let's just check if the file exists and has content.
if [ ! -f output.txt ]; then
    echo "Error: output.txt not found!"
    exit 1
fi

# Compare with baseline_output.txt
if diff -q output.txt ../baseline_output.txt > /dev/null; then
    echo "Regression Test Passed: Output matches baseline."
else
    echo "Regression Test FAILED: Output differs from baseline."
    # Optional: show differences
    # diff output.txt ../baseline_output.txt | head -n 20
fi
