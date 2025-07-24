#pragma once
namespace StyleHelper
{
    enum class Mode { Day, Night };

    /// Determine initial mode based on local time
    Mode initialMode();

    /// Apply palette and styles for the chosen mode
    void apply(Mode mode);
}
