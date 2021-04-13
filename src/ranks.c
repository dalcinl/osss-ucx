/* For license: see LICENSE file at top-level */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif /* HAVE_CONFIG_H */

#include "shmemc.h"
#include "shmemu.h"
#include "shmem/api.h"

#ifdef ENABLE_PSHMEM
#pragma weak shmem_my_pe = pshmem_my_pe
#define shmem_my_pe pshmem_my_pe
#pragma weak shmem_n_pes = pshmem_n_pes
#define shmem_n_pes pshmem_n_pes
#endif /* ENABLE_PSHMEM */

int
shmem_my_pe(void)
{
    int my;

    SHMEMU_CHECK_INIT();

    my = shmemc_team_my_pe(SHMEM_TEAM_WORLD);

    logger(LOG_RANKS, "%s() -> %d", __func__, my);

    return my;
}

int
shmem_n_pes(void)
{
    int n;

    SHMEMU_CHECK_INIT();

    n = shmemc_team_n_pes(SHMEM_TEAM_WORLD);

    logger(LOG_RANKS, "%s() -> %d", __func__, n);

    return n;
}
