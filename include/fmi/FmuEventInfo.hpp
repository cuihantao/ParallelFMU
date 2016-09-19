/** @addtogroup FMI
 *  @{
 *  \copyright TU Dresden ZIH. All rights reserved.
 *  \authors Martin Flehmig, Marc Hartung, Marcus Walther
 *  \date Oct 2015
 */

#ifndef INCLUDE_FMI_FMUEVENTINFO_HPP_
#define INCLUDE_FMI_FMUEVENTINFO_HPP_


#include "fmusdk.h"
#ifdef USE_FMILIB
#include <fmilib.h>
#endif
#include "BasicTypedefs.hpp"

namespace FMI
{
    /**
     * A wrapper class to work with the event informations generated by the concrete FMU implementation.
     */
    class FmuEventInfo
    {
     public:
        /**
         * Create a new instance of the event information class with the given parameters. For more detail, look into the FMI 1.0 standard.
         * @param iterationConverged True if the event handling has found the root of the zero crossing.
         * @param stateValueReferencesChanged True if the references to the state values have changed after an event.
         * @param stateValuesChanged True if the state values have changed after an event.
         * @param terminateSimulation True if the simulation should be terminated.
         * @param upcomingTimeEvent True if there is at least one time event left.
         * @param nextEventTime The time point_type of the next time event. This value is not used if upcomingTimeEvent is false.
         */
        FmuEventInfo(bool_type iterationConverged = false, bool_type stateValueReferencesChanged = false, bool_type stateValuesChanged = false,
                     bool_type terminateSimulation = false, bool_type upcomingTimeEvent = false, double nextEventTime = -1.0);

        /**
         * Delete the event info object.
         */
        virtual ~FmuEventInfo() = default;

        /**
         * Check if the iteration convergence criteria was fulfilled.
         * @return True if the event handling has found the root of the zero crossing.
         */
        bool_type isIterationConverged() const;

        /**
         * Set the iteration convergence indicator.
         * @param iterationConverged Set to true if the iteration convergence criteria was fulfilled.
         */
        void setIterationConverged(bool_type iterationConverged);

        /**
         * Get the point_type in time for the next time event. The value is only useful if upcomingTimeEvent is true.
         * @return The point_type in time for the next time event.
         */
        double getNextEventTime() const;

        /**
         * Set the point_type in time for the next time event.
         * @note Don't forget to set upcomingTimeEvent to true.
         * @param nextEventTime The point_type in time for the next time event.
         */
        void setNextEventTime(double nextEventTime);

        /**
         * Get an indicator which is true if the state value references have changed during the last event.
         * @return True if the state value references have changed.
         */
        bool_type isStateValueReferencesChanged() const;

        /**
         * Set this value to true if the state value references have changed during the last event.
         * @param stateValueReferencesChanged The new indicator value.
         */
        void setStateValueReferencesChanged(bool_type stateValueReferencesChanged);

        /**
         * Get an indicator which is true if the state values have changed during the last event.
         * @return True if the state values have changed.
         */
        bool_type isStateValuesChanged() const;

        /**
         * Set this value to true if the state values have changed during the last event.
         * @param stateValuesChanged The new indicator value.
         */
        void setStateValuesChanged(bool_type stateValuesChanged);

        /**
         * Get an indicator which is true if the simulation should be terminated.
         * @return True if the simulation should be terminated.
         */
        bool_type isTerminateSimulation() const;

        /**
         * Set this value to true if the simulation should be terminated.
         * @param terminateSimulation The indicator for the termination.
         */
        void setTerminateSimulation(bool_type terminateSimulation);

        /**
         * Get an indicator which is true if an time event is upcoming.
         * @return True if an time event is upcoming.
         */
        bool_type isUpcomingTimeEvent() const;

        /**
         * Set this value to true if an time event is upcoming.
         * @param upcomingTimeEvent The time event indicator.
         */
        void setUpcomingTimeEvent(bool_type upcomingTimeEvent);

        void assign(const fmiEventInfo & in);
#ifdef USE_FMILIB
        void assign(const fmi1_event_info_t & in);
#endif

     private:
        bool_type _iterationConverged;
        bool_type _stateValueReferencesChanged;
        bool_type _stateValuesChanged;
        bool_type _terminateSimulation;
        bool_type _upcomingTimeEvent;
        double _nextEventTime;
    };
} /* namespace FMI */

#endif /* INCLUDE_FMI_FMUEVENTINFO_HPP_ */
/**
 * @}
 */
