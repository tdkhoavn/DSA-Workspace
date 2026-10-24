#!/usr/bin/env bash
# Scaffold a new problem folder from templates/problem.
#
# Usage: tools/new-problem.sh <lesson-dir> <slug> "<Title>" <url> <easy|medium|hard>
# Example:
#   tools/new-problem.sh lessons/01-arrays/02-static-arrays remove-element \
#       "Remove Element" https://leetcode.com/problems/remove-element/ easy
set -euo pipefail

if [ $# -ne 5 ]; then
    sed -n '2,8p' "$0" | sed 's/^# \{0,1\}//'
    exit 1
fi

lesson_dir=${1%/} slug=$2 title=$3 url=$4 level=$5
root=$(cd "$(dirname "$0")/.." && pwd)
dest="$root/$lesson_dir/$slug"

case $level in
    easy) difficulty="🟢 Easy" ;;
    medium) difficulty="🟡 Medium" ;;
    hard) difficulty="🔴 Hard" ;;
    *)
        echo "error: difficulty must be easy, medium or hard" >&2
        exit 1
        ;;
esac

if [ -e "$dest" ]; then
    echo "error: $dest already exists" >&2
    exit 1
fi

# "02-static-arrays" -> lesson number "2", lesson title "Static Arrays".
lesson=$(basename "$lesson_dir")
lesson_number=$((10#${lesson%%-*}))
lesson_title=$(printf '%s' "${lesson#*-}" | sed -E 's/-/ /g; s/(^| )([a-z])/\1\u\2/g')

# "Remove Element" -> "RemoveElement" (a valid GoogleTest suite name).
suite=$(printf '%s' "$title" | sed -E 's/(^|[^A-Za-z0-9])([a-z])/\1\u\2/g; s/[^A-Za-z0-9]//g')

mkdir -p "$dest"
for file in solution.hpp solution_test.cpp README.md; do
    sed -e "s|__TITLE__|$title|" -e "s|__URL__|$url|" -e "s|__SUITE__|$suite|" \
        -e "s|__DIFFICULTY__|$difficulty|" -e "s|__LESSON_NUMBER__|$lesson_number|" \
        -e "s|__LESSON_TITLE__|$lesson_title|" \
        "$root/templates/problem/$file" >"$dest/$file"
done

echo "Created $lesson_dir/$slug/ (re-load CMake in CLion to see the new target)"
