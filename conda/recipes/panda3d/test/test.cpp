// Include all the stuff
#include <panda3d/pandaFramework.h>
#include <panda3d/pandaSystem.h>
#include <panda3d/configFlags.h> // add this header to force compile with configFlags

int main(int argc, char *argv[]) {
  GraphicsOutput *windowOutput;
  auto dummy = windowOutput->get_gsg();
  // PointerTo<GraphicsOutput> m_normalDepthBuffer;
  // m_normalDepthBuffer->set_inverted(windowOutput->get_gsg()->get_copy_texture_inverted());
  return 0;
}
