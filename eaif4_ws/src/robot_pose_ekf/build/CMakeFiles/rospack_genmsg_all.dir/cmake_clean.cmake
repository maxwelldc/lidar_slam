file(REMOVE_RECURSE
  "../srv_gen"
  "../srv_gen"
  "../src/robot_pose_ekf/srv"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/rospack_genmsg_all.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
