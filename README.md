# Solutions for Ray Tracing in One Weekend

https://raytracing.github.io/books/RayTracingInOneWeekend.html#overview

- Setup for vscode and MacBook M2 
- Add `export PATH="/opt/homebrew/bin:$PATH"` to `~/.bash_profile` to setup `brew`
- Uses `clang` from Xcode development tools
- Uses `clang-format` from `brew`
- Used C++ and clang-format extensions for VSCode


## Compile 

```
clang++ main.cpp -std=c++11 -o main
```

## Run

```
./main > image_test.ppm
```

## Result

![Resulting render](result.jpg) 


## Intermediate results (`images` folder)

1. Initial red and green image plane `image.ppm`

2. Rendering of blue gradient 16:9 image is `image1.ppm`

3. Rendering of a sphere `image2.ppm`

4. Sphere shaded with surface normals `image3.ppm`

5. Two spheres rendered with camera and interval class shaded with surface normals `image4.ppm`

6. Added antialiasing `image5.ppm`

7. First render of a diffuse sphere `image6.ppm`

8. Render with diffuse and metal materials `image7.ppm`

9. Fuzzed metal `image8.ppm`

10. Dielectric `image9.ppm` 

11. Dielectric and metal `image10.ppm`

12. Longer distance (wide angle) rendering `image11.ppm`

13. Close up rendering `image12.ppm`

14. Close up rendering with defocus `image13.ppm`
