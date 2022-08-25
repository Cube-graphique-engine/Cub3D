# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathmart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 14:46:28 by mathmart          #+#    #+#              #
#    Updated: 2022/07/01 20:19:17 by mathismartini    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.21)
project(cube C)

set(CMAKE_C_STANDARD 99)

#Get all c files
file(GLOB_RECURSE LIBFT RELATIVE ${CMAKE_SOURCE_DIR} "./lib/libft/*.c")
file(GLOB_RECURSE MLX RELATIVE ${CMAKE_SOURCE_DIR} "./lib/minilibx/*.c" "./lib/minilibx/*.m")
file(GLOB_RECURSE BETTER RELATIVE ${CMAKE_SOURCE_DIR} "./lib/bettermlx/*.c")
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")

#Get all h files
file(GLOB_RECURSE HEADER RELATIVE ${CMAKE_SOURCE_DIR} "./include/*.h")
file(GLOB_RECURSE HEADER RELATIVE ${CMAKE_SOURCE_DIR} "./lib/libft/*.h")
file(GLOB_RECURSE HEADER RELATIVE ${CMAKE_SOURCE_DIR} "./lib/minilibx/*.h")
file(GLOB_RECURSE HEADER RELATIVE ${CMAKE_SOURCE_DIR} "./lib/bettermlx/*.h")

#Adding library
add_library(libft ${LIBFT})
add_library(mlx ${MLX})
add_library(better ${BETTER})

include_directories(${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/lib/libft/
        ${CMAKE_SOURCE_DIR}/lib/minilibx/
        ${CMAKE_SOURCE_DIR}/lib/bettermlx/
        )

set(CMAKE_C_FLAGS "-O3 -Ofast -flto -march=native -ffast-math -DSTRINGPUTX11 -Wno-deprecated-declarations -fsanitize=address -g3")

add_executable(cube3D ${SOURCES} src/parsing/utils/check_color.c)

target_link_libraries(cube3D "-framework OpenGL -framework AppKit" m libft mlx better)