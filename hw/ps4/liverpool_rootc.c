/*
 * QEMU model of Liverpool Processor Root Complex device.
 *
 * Copyright (c) 2017 Alexandro Sanchez Bach
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "liverpool.h"
#include "qemu/osdep.h"
#include "hw/pci/pci.h"

typedef struct LiverpoolRootComplexState {
    PCIDevice parent_obj;
} LiverpoolRootComplexState;

static void liverpool_rootc_realize(PCIDevice *dev, Error **errp)
{
}

static void liverpool_rootc_class_init(ObjectClass *klass, void *data)
{
    PCIDeviceClass *pc = PCI_DEVICE_CLASS(klass);

    pc->vendor_id = 0x1022;
    pc->device_id = 0x1436;
    pc->revision = 1;
    pc->class_id = PCI_CLASS_BRIDGE_HOST;
    pc->realize = liverpool_rootc_realize;
}

static const TypeInfo liverpool_rootc_info = {
    .name          = TYPE_LIVERPOOL_ROOTC,
    .parent        = TYPE_PCI_DEVICE,
    .instance_size = sizeof(LiverpoolRootComplexState),
    .class_init    = liverpool_rootc_class_init,
    .interfaces    = (InterfaceInfo[]) {
        { INTERFACE_PCIE_DEVICE },
        { }
    },
};

static void liverpool_register_types(void)
{
    type_register_static(&liverpool_rootc_info);
}

type_init(liverpool_register_types)
