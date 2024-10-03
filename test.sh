#!/bin/sh

GREEN="\e[32m"
BLUE="\e[34m"
RESET="\e[0m"


make all

echo -e "${GREEN}Let's test some stuff dude${RESET}"

echo -e "${BLUE}\n\ntest 1: invalid key\n${RESET}\n./cub3d maps/tests/invalid_key.cub\nOutput:	"

./cub3d maps/tests/invalid_key.cub

echo -e "${BLUE}\n\ntest 2: invalid map\n${RESET}\n./cub3d maps/tests/invalid_map.cub\nOutput:	"

./cub3d maps/tests/invalid_map.cub

echo -e "${BLUE}\n\ntest 3: unexpexted token in map\n${RESET}\n./cub3d maps/tests/invalid_map2.cub\nOutput:	"

./cub3d maps/tests/invalid_map2.cub

echo -e "${BLUE}\n\ntest 4: invalid rgb\n${RESET}\n./cub3d maps/tests/invalid_rgb.cub\nOutput:	"

./cub3d maps/tests/invalid_rgb.cub

echo -e "${BLUE}\n\ntest 5: rgb over 255\n${RESET}\n./cub3d maps/tests/invalid_rgb2.cub\nOutput:	"

./cub3d maps/tests/invalid_rgb2.cub

echo -e "${BLUE}\n\ntest 6: missing player\n${RESET}\n./cub3d maps/tests/missing_player.cub\nOutput:	"

./cub3d maps/tests/missing_player.cub

echo -e "${BLUE}\n\ntest 7: missing texture\n${RESET}\n./cub3d maps/tests/missing.cub\nOutput:	"

./cub3d maps/tests/missing.cub

echo -e "${BLUE}\n\ntest 8: missing rgb\n${RESET}\n./cub3d maps/tests/missing2.cub\nOutput:	"

./cub3d maps/tests/missing2.cub

echo -e "${BLUE}\n\ntest 9: multiple textures\n${RESET}\n./cub3d maps/tests/multiple.cub\nOutput:	"

./cub3d maps/tests/multiple.cub

echo -e "${BLUE}\n\ntest 10: multiple rgb\n${RESET}\n./cub3d maps/tests/multiple2.cub\nOutput:	"

./cub3d maps/tests/multiple2.cub

echo -e "${BLUE}\n\ntest 11: not .cub\n${RESET}\n./cub3d maps/tests/nope.no\nOutput:"

./cub3d maps/tests/nope.no
