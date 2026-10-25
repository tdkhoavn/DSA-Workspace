#!/usr/bin/env bash
# Generate one CLion run configuration per problem and per playground in .run/.
#
# Each configuration is a "CMake Application" that builds and runs only that
# target, so a single problem's tests can be run or debugged on its own.
# Target names follow CMakeLists.txt: "<lesson>-<problem>" and "<lesson>-pg-<name>".
#
# Usage: tools/gen-run-configs.sh   (safe to re-run; also called by new-problem.sh)
set -euo pipefail

root=$(cd "$(dirname "$0")/.." && pwd)
out="$root/.run"
mkdir -p "$out"
rm -f "$out"/*.run.xml

write_config() {
    local target=$1
    cat >"$out/$target.run.xml" <<EOF
<component name="ProjectRunConfigurationManager">
  <configuration default="false" name="$target" type="CMakeRunConfiguration" factoryName="Application" REDIRECT_INPUT="false" ELEVATE="false" USE_EXTERNAL_CONSOLE="false" EMULATE_TERMINAL="false" PASS_PARENT_ENVS_2="true" PROJECT_NAME="DSAWorkspace" TARGET_NAME="$target" CONFIG_NAME="Debug" RUN_TARGET_PROJECT_NAME="DSAWorkspace" RUN_TARGET_NAME="$target">
    <method v="2">
      <option name="com.jetbrains.cidr.execution.CidrBuildBeforeRunTaskProvider\$BuildBeforeRunTask" enabled="true" />
    </method>
  </configuration>
</component>
EOF
}

count=0
cd "$root"
while IFS= read -r test_file; do
    problem_dir=$(dirname "$test_file")
    lesson=$(basename "$(dirname "$problem_dir")")
    write_config "${lesson%%-*}-$(basename "$problem_dir")"
    count=$((count + 1))
done < <(find lessons -name '*_test.cpp' | sort)

while IFS= read -r playground_file; do
    lesson=$(basename "$(dirname "$(dirname "$playground_file")")")
    name=$(basename "$playground_file" .cpp)
    write_config "${lesson%%-*}-pg-$name"
    count=$((count + 1))
done < <(find lessons -path '*/playground/*.cpp' | sort)

echo "Generated $count run configurations in .run/"
