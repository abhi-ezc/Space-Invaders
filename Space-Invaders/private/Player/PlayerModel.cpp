#include "./../../public/player/PlayerModel.h"

namespace Player
{
    PlayerModel::PlayerModel()
    {
        m_player_score = 0;
        m_player_state = PlayerState::LIMBO;
    }

    PlayerModel::~PlayerModel() = default;

    void PlayerModel::initialize()
    {
        reset(); // setting up initial variables
    }

    void PlayerModel::update() { }

    void PlayerModel::render() { }

    void PlayerModel::reset()
    {
        m_current_player_position = m_initial_player_position;
        m_player_state = PlayerState::ALIVE;
        m_player_score = 0;
    }

    sf::Vector2f PlayerModel::getPlayerPosition() { return m_current_player_position; }

    bool PlayerModel::isPlayerAlive() { return m_player_state == PlayerState::ALIVE; }

    PlayerState PlayerModel::getPlayerState() { return m_player_state; }

    int PlayerModel::getPlayerScore() { return m_player_score; }

    void PlayerModel::setPlayerState(PlayerState newPlayerState) { m_player_state = newPlayerState; }

    void PlayerModel::setPlayerScore(int score) { m_player_score = score; }

    void PlayerModel::setPlayerPosition(sf::Vector2f position) { m_current_player_position = position; }
}
