/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:20:38 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/16 11:41:34 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * Zoom over fractal and draw fractal again with applied zoom.
*/
static int scroll_hook(int code, int x, int y, t_fractol **fractol)
{
  (void)x;
  (void)y;
  if (code == MOUSE_SCROLL_UP || code == MOUSE_SCROLL_DOWN)
  {
    if (code == MOUSE_SCROLL_DOWN)
      (*fractol)->zoom *= ZOOM_FACTOR;
    if (code == MOUSE_SCROLL_UP)
      (*fractol)->zoom /= ZOOM_FACTOR;
    draw_fractal(*fractol);
  }
  return (0);
}

static int  key_hook(int code, t_fractol **fractol)
{
  if (code == ESC_KEY)
    destroy_fractol(fractol);
  if (code == C_KEY)
    change_color(fractol);
  if (code == ARROW_UP_KEY || code == ARROW_DOWN_KEY
    || code == ARROW_LEFT_KEY || code == ARROW_RIGHT_KEY)
  {
    if (code == ARROW_UP_KEY)
      (*fractol)->middle_y -= MOVEMENT_FACTOR / (*fractol)->zoom;
    if (code == ARROW_DOWN_KEY)
      (*fractol)->middle_y += MOVEMENT_FACTOR / (*fractol)->zoom;
    if (code == ARROW_RIGHT_KEY)
      (*fractol)->middle_x += MOVEMENT_FACTOR / (*fractol)->zoom;
    if (code == ARROW_LEFT_KEY)
      (*fractol)->middle_x -= MOVEMENT_FACTOR / (*fractol)->zoom;
    draw_fractal(*fractol);
  }

  return (0);
}

static int  on_close_window(t_fractol **fractol)
{
  destroy_fractol(fractol);
  return (0);
}

void  init_handlers(t_fractol **fractol)
{
  mlx_mouse_hook((*fractol)->win, scroll_hook, fractol);
  mlx_key_hook((*fractol)->win, key_hook, fractol);
  mlx_hook((*fractol)->win, ON_DESTROY, 0, on_close_window, fractol);
}