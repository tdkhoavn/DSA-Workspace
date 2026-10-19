#!/usr/bin/env bash
# Scaffold a new problem folder from templates/problem.
#
# Usage: tools/new-problem.sh <lesson-dir> <slug> "<Title>" <url>
# Example:
#   tools/new-problem.sh lessons/01-arrays/02-static-arrays remove-element \
#       "Remove Element" https://leetcode.com/problems/remove-element/
set -euo pipefail

if [ $# -ne 4 ]; then
    sed -n '2,8p' "$0" | sed 's/^# \{0,1\}//'
    exit 1
fi

lesson_dir=$1 slug=$2 title=$3 url=$4
root=$(cd "$(dirname "$0")/.." && pwd)
dest="$root/$lesson_dir/$slug"

if [ -e "$dest" ]; then
    echo "error: $dest already exists" >&2
    exit 1
fi

# "Remove Element" -> "RemoveElement" (a valid GoogleTest suite name).
suite=$(printf '%s' "$title" | sed -E 's/(^|[^A-Za-z0-9])([a-z])/\1\u\2/g; s/[^A-Za-z0-9]//g')

mkdir -p "$dest"
for file in solution.hpp solution_test.cpp; do
    sed -e "s|__TITLE__|$title|" -e "s|__URL__|$url|" -e "s|__SUITE__|$suite|" \
        "$root/templates/problem/$file" >"$dest/$file"
done

echo "Created $lesson_dir/$slug/ (re-load CMake in CLion to see the new target)"
