/* gskglrenderer.h
 *
 * Copyright 2020 Christian Hergert <chergert@redhat.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#pragma once

/* Allow direct inclusion: if we are not inside <gsk/gsk.h> and not building
 * GTK itself, pull in the umbrella header first so that all prerequisites
 * (gdk version macros, GskRenderer forward-decl, …) are available.
 * The #pragma once above makes the subsequent #include <gsk/gsktypes.h>
 * a no-op if gsktypes.h was already included by gsk.h.
 */
#if !defined (__GSK_H_INSIDE__) && !defined (GTK_COMPILATION)
#include <gsk/gsk.h>
#endif

#include <gsk/gsktypes.h>

G_BEGIN_DECLS

#define GSK_TYPE_GL_LEGACY_RENDERER (gsk_gl_legacy_renderer_get_type ())

#define GSK_GL_LEGACY_RENDERER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GSK_TYPE_GL_LEGACY_RENDERER, GskGLLegacyRenderer))
#define GSK_IS_GL_LEGACY_RENDERER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GSK_TYPE_GL_LEGACY_RENDERER))
#define GSK_GL_LEGACY_RENDERER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST    ((klass), GSK_TYPE_GL_LEGACY_RENDERER, GskGLLegacyRendererClass))
#define GSK_IS_GL_LEGACY_RENDERER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE    ((klass), GSK_TYPE_GL_LEGACY_RENDERER))
#define GSK_GL_LEGACY_RENDERER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS  ((obj), GSK_TYPE_GL_LEGACY_RENDERER, GskGLLegacyRendererClass))

typedef struct _GskGLLegacyRenderer      GskGLLegacyRenderer;
typedef struct _GskGLLegacyRendererClass GskGLLegacyRendererClass;

GDK_AVAILABLE_IN_4_2
GType        gsk_gl_legacy_renderer_get_type (void) G_GNUC_CONST;

GDK_AVAILABLE_IN_4_2
GskRenderer *gsk_gl_legacy_renderer_new      (void);

G_DEFINE_AUTOPTR_CLEANUP_FUNC (GskGLLegacyRenderer, g_object_unref)

G_END_DECLS
