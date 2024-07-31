#pragma once

namespace Graphic
{
    class GraphicService;
}
namespace Event
{
    class EventService;
}
namespace Player
{
    class PlayerService;
}
namespace Time
{
    class TimeService;
}

namespace Global
{

    // ServiceLocator Class Summary: This class manages access to various services in the application.
    class ServiceLocator {
        private:
        Graphic::GraphicService* graphicService;
        Event::EventService* eventService;
        Player::PlayerService* playerService;
        Time::TimeService* timeService;

        // Constructor for initializing the ServiceLocator.
        ServiceLocator();

        // Destructor for cleaning up resources upon object deletion.
        ~ServiceLocator();

        // Private Methods:
        void createServices(); // Creates instances of all services.
        void clearAllServices(); //	Deletes and deallocates memory for all services.

        public:
        // Public Methods:
        static ServiceLocator* getInstance();
        // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

        void initialize(); // Initializes the ServiceLocator.
        void update(); // Updates all services.
        void render(); // Renders using the services.

        // Methods to Get Specific Services: 
        Event::EventService* getEventService(); // Retrieve the EventService instance
        Graphic::GraphicService* getGraphicService(); // Retrieve the GraphicService instance
        Player::PlayerService* getPlayerService(); // Retrieve the PlayerService instance
        Time::TimeService* getTimeService();
    };
}


