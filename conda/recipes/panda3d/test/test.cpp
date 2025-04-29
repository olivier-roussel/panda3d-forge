// Include all the stuff
#include <panda3d/pandaFramework.h>
#include <panda3d/pandaSystem.h>
#include <panda3d/configFlags.h> // add this header to force compile with configFlags

int main(int argc, char *argv[]) {
  GraphicsOutput *windowOutput;
  GraphicsStateGuardian* gsg = windowOutput->get_gsg();

  // XXX faulty call that makes clang-cl linker fail with
  // error: undefined symbol: __declspec(dllimport) private: static long volatile ConfigFlags::_global_modified
  auto dummy2 = gsg->get_copy_texture_inverted(); 
  
  return 0;
}
