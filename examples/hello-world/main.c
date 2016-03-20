/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Hello World application
 *
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 * @author      Ludwig Knüpfer <ludwig.knuepfer@fu-berlin.de>
 *
 * @}
 */

#include <stdio.h>
#include "shell.h"
#include "thread.h"
#include "xtimer.h"

#include "net/ipv6/addr.h"
#include "net/gnrc/netif.h"
#include "net/gnrc/ipv6/netif.h"

void ps(void);

const char *blink_name = "blink";
static char blink_stack [THREAD_STACKSIZE_DEFAULT];

static void *blink_function (void *arg)
{
    xtimer_t xtimer;

    while (1)
    {
        LED_RED_TOGGLE;

        xtimer_set_wakeup(&xtimer, 500000, thread_getpid());

        thread_sleep();
    }

    return NULL;
}

int main(void)
{
    kernel_pid_t ifs[GNRC_NETIF_NUMOF];

    puts("Hello World!");

    printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
    printf("This board features a(n) %s MCU.\n", RIOT_MCU);

    /* create blink thread */
    thread_create(blink_stack, sizeof(blink_stack),
        THREAD_PRIORITY_MAIN,
        THREAD_CREATE_WOUT_YIELD | THREAD_CREATE_STACKTEST,
        blink_function, NULL, blink_name);

    /* start shell */
    ps ();

    /* get the first IPv6 interface and prints its address */
    size_t numof = gnrc_netif_get(ifs);
    if (numof > 0) {
        gnrc_ipv6_netif_t *entry = gnrc_ipv6_netif_get(ifs[0]);
        for (int i = 0; i < GNRC_IPV6_NETIF_ADDR_NUMOF; i++) {
//            if ((ipv6_addr_is_link_local(&entry->addrs[i].addr)) && !(entry->addrs[i].flags & GNRC_IPV6_NETIF_ADDR_FLAGS_NON_UNICAST)) {
                char ipv6_addr[IPV6_ADDR_MAX_STR_LEN];
                ipv6_addr_to_str(ipv6_addr, &entry->addrs[i].addr, IPV6_ADDR_MAX_STR_LEN);
                printf("My address is %s\n", ipv6_addr);
  //          }
        }
    }



    puts("All up, running the shell now");
    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
