import re,subprocess,sys
F='Source/gfx/draw_area.cpp'
src=open(F).read()
start=src.index('void TDrawArea::SetMode_460EC0(int mode, unsigned char flag)\n{')
end=src.index('\n}\n',start)+3
orig=src
V={}
V['a']='''
    field_EC = mode;
    if (mode) {
        field_FC = flag;
        if (field_3C && field_0 && field_0->type_3C == 2) {
            int entries[2];
            entries[0] = flag;
            entries[1] = flag;
            field_3C->lpVtbl->fn_74(field_3C, 8, entries);
        }
    } else
        field_FC = 0xff;
'''
V['b']='''
    field_EC = mode;
    if (mode) {
        field_FC = flag;
        if (field_3C && field_0 && field_0->type_3C == 2) {
            int entries[2];
            entries[0] = flag;
            entries[1] = flag;
            field_3C->lpVtbl->fn_74(field_3C, 8, entries);
        }
        return;
    }
    field_FC = 0xff;
'''
V['c']='''
    int entries[2];
    field_EC = mode;
    if (mode) {
        field_FC = flag;
        if (field_3C && field_0 && field_0->type_3C == 2) {
            entries[0] = flag;
            entries[1] = flag;
            field_3C->lpVtbl->fn_74(field_3C, 8, entries);
        }
    } else
        field_FC = 0xff;
'''
V['d']='''
    field_EC = mode;
    if (!mode) {
        field_FC = 0xff;
    } else {
        field_FC = flag;
        if (field_3C)
          if (field_0)
            if (field_0->type_3C == 2) {
            int entries[2];
            entries[0] = flag;
            entries[1] = flag;
            field_3C->lpVtbl->fn_74(field_3C, 8, entries);
        }
    }
'''

CALL='''            int entries[2];
            entries[0] = flag;
            entries[1] = flag;
            field_3C->lpVtbl->fn_74(field_3C, 8, entries);
'''
V['e']='''
    field_EC = mode;
    if (mode) {
        field_FC = flag;
        if (!field_3C) return;
        if (!field_0) return;
        if (field_0->type_3C != 2) return;
'''+CALL+'''
    } else
        field_FC = 0xff;
'''
V['f']='''
    field_EC = mode;
    if (mode == 0) goto off;
    field_FC = flag;
    if (field_3C && field_0 && field_0->type_3C == 2) {
'''+CALL+'''    }
    return;
off:
    field_FC = 0xff;
'''
V['g']='''
    field_EC = mode;
    if (mode) {
        field_FC = flag;
        if (field_3C && field_0 && field_0->type_3C == 2) {
'''+CALL+'''        }
        else return;
    } else
        field_FC = 0xff;
'''
V['h']='''
    field_EC = mode;
    if (mode) {
        field_FC = flag;
        if (field_3C == 0 || field_0 == 0 || field_0->type_3C != 2) return;
'''+CALL+'''    } else
        field_FC = 0xff;
'''
V['i']='''
    field_EC = mode;
    if (mode) {
        field_FC = flag;
        if (field_3C && field_0 && field_0->type_3C == 2) {
'''+CALL+'''        }
    } else {
        field_FC = 0xff;
        return;
    }
'''


DECL='''struct DDSurf {
'''+''.join('    virtual void __stdcall v%d();\n'%i for i in range(29))+'''    virtual long __stdcall SetColorKey(unsigned long flags, void* key);
};
'''
V['j']='''
    field_EC = mode;
    if (mode) {
        field_FC = flag;
        if (field_3C && field_0 && field_0->type_3C == 2) {
            int entries[2];
            entries[0] = flag;
            entries[1] = flag;
            ((DDSurf*)field_3C)->SetColorKey(8, entries);
        }
    } else
        field_FC = 0xff;
'''


HELP='''static inline void ApplyKey(DDObj* surf, DDObj* sys, unsigned char flag)
{
    if (surf && sys && sys->type_3C == 2) {
        int entries[2];
        entries[0] = flag;
        entries[1] = flag;
        surf->lpVtbl->fn_74(surf, 8, entries);
    }
}
static inline void ApplyKey2(DDObj* surf, DDObj* sys, unsigned char flag)
{
    if (!surf || !sys || sys->type_3C != 2) return;
    int entries[2];
    entries[0] = flag;
    entries[1] = flag;
    surf->lpVtbl->fn_74(surf, 8, entries);
}
'''
V['k']='''
    field_EC = mode;
    if (mode) {
        field_FC = flag;
        ApplyKey(field_3C, field_0, flag);
    } else
        field_FC = 0xff;
'''
V['l']='''
    field_EC = mode;
    if (mode) {
        field_FC = flag;
        ApplyKey2(field_3C, field_0, flag);
    } else
        field_FC = 0xff;
'''
V['m']='''
    field_EC = mode;
    if (mode) {
        field_FC = flag;
        ApplyKey2(field_3C, field_0, flag);
        return;
    }
    field_FC = 0xff;
'''


V['n']='''
    field_EC = mode;
    switch (mode) {
    case 0:
        field_FC = 0xff;
        break;
    default:
        field_FC = flag;
        if (field_3C && field_0 && field_0->type_3C == 2) {
'''+CALL+'''        }
        break;
    }
'''
V['o']='''
    field_EC = mode;
    if (mode) {
        field_FC = flag;
        do {
            if (!field_3C) break;
            if (!field_0) break;
            if (field_0->type_3C != 2) break;
'''+CALL+'''        } while (0);
        return;
    }
    field_FC = 0xff;
'''
V['p']='''
    field_EC = mode;
    if (mode) {
        field_FC = flag;
        if (!field_3C || !field_0 || field_0->type_3C != 2) goto done;
'''+CALL+'''done:
        return;
    }
    field_FC = 0xff;
'''
V['q']='''
    if ((field_EC = mode) != 0) {
        field_FC = flag;
        if (field_3C && field_0 && field_0->type_3C == 2) {
'''+CALL+'''        }
    } else
        field_FC = 0xff;
'''


V['r']='''
    field_EC = mode;
    if (mode) goto on;
    field_FC = 0xff;
    return;
on:
    field_FC = flag;
    if (field_3C && field_0 && field_0->type_3C == 2) {
'''+CALL+'''    }
'''
V['s']='''
    field_EC = mode;
    if (mode == 0) {
        field_FC = 0xff;
    } else {
        field_FC = flag;
        if (field_3C && field_0 && field_0->type_3C == 2) {
'''+CALL+'''        }
    }
'''


MAIN='''    field_FC = flag;
    if (field_3C && field_0 && field_0->type_3C == 2) {
'''+CALL+'''    }
'''
V['t']='''
    field_EC = mode;
    while (!mode) { field_FC = 0xff; return; }
'''+MAIN
V['u']='''
    field_EC = mode;
    while (mode) {
'''+MAIN+'''        return;
    }
    field_FC = 0xff;
'''
V['v']='''
    field_EC = mode;
    for (; mode; ) {
'''+MAIN+'''        break;
    }
    if (!mode) field_FC = 0xff;
'''

for k in (sys.argv[1:] or V):
    open(F,'w').write(src[:start]+(DECL if k=='j' else HELP if k in 'klm' else '')+'void TDrawArea::SetMode_460EC0(int mode, unsigned char flag)\n{'+V[k]+'}\n'+src[end:])
    out=subprocess.run(['./venv/bin/python','Scripts/match.py',F],capture_output=True,text=True).stdout
    m=[l for l in out.splitlines() if '0x460EC0' in l]
    print(k,m, out.count('  ! '))
open(F,"w").write(orig)
