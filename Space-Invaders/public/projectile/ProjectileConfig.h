#pragma once
namespace Projectile {
	enum class ProjectileDirection {
		UP,
		DOWN
	};

	enum class ProjectileLifecycle {
		INIT,
		UPDATE,
		RENDER,
		DESTROY,
	};
}
