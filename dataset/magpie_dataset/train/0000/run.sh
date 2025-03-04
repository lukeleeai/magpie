#!/bin/sh

./minisat data/uf50-01.cnf $@
./minisat data/uf50-02.cnf $@
./minisat data/uf100-01.cnf $@
./minisat data/uf100-02.cnf $@
./minisat data/uf150-01.cnf $@
./minisat data/uf150-02.cnf $@
./minisat data/uf200-01.cnf $@
./minisat data/uf200-02.cnf $@
./minisat data/uf250-01.cnf $@
./minisat data/uf250-02.cnf $@

./minisat data/uuf50-01.cnf $@
./minisat data/uuf50-02.cnf $@
./minisat data/uuf100-01.cnf $@
./minisat data/uuf100-02.cnf $@
./minisat data/uuf150-01.cnf $@
./minisat data/uuf150-02.cnf $@
./minisat data/uuf200-01.cnf $@
./minisat data/uuf200-02.cnf $@
./minisat data/uuf250-01.cnf $@
./minisat data/uuf250-02.cnf $@

exit 0



# #!/usr/bin/env bash

# mkdir -p perf
# perf stat -e cycles,task-clock,instructions ./build/src_code < ~/magpie/dataset/public_test_cases/p00000/input.1.txt 2>&1 | awk '/cycles/ {cycles=$1} /elapsed/ {time=$1} /instructions/ {instructions=$1} END {print cycles, time, instructions}'
